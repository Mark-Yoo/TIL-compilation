# Asynchronous Data Queries (비동기 데이터 쿼리)

---

Recoil은 데이터 플로우 그래프를 통해 상태를 매핑하는 방법과 파생된 상태를 리액트 컴포넌트에 제공합니다. 가장 강력한 점은 graph에 속한 함수들도 비동기가 될 수 있다는 것입니다. 이는 비동기 함수들을 동기 리액트 컴포넌트 렌더 함수에서 사용하기 쉽게 해줍니다. Recoil은 동기와 비동기 함수들을 selector의 데이터 플로우 그래프에서 균일하게 혼합하게 해줍니다. Selector `get`콜백에서 나온 값 그 자체 대신 프로미스를 리턴하면 인터페이스는 정확하게 그대로 유지됩니다. 이들은 Selector일 뿐이므로 다른 selector들에 의존하여 데이터를 추가로 변환 할 수도 있습니다.

Selector는 비동기 데이터를 Recoil의 데이터 플로우 그래프로 포함하는 방법 중 하나로 사용될 수 있습니다. Selector는 "idempotent" 함수를 대표한다는 것을 숙지하고 있어야합니다: 주어진 인풋들로 항상 같은 결과를 만들어냅니다.(적어도 애플리케이션의 생명주기동안은 말이죠). 이것은 selector 평가가 캐시되거나, 재시작되거나, 혹은 수차례에 걸쳐서 실행될 수 있으므로 중요합니다. selector가 보통 읽기 전용 DB 쿼리를 모델링하는데에 좋은 방법이라고 하는 이유도 이 때문입니다. 변경 가능한 데이터의 경우, [Query Refresh](https://recoiljs.org/docs/guides/asynchronous-data-queries#query-refresh)를 사용하거나 변경가능한 상태를 동기화하거나 상태를 유지하거나 혹은 다른 부수효과에 대해서 실험적인 [Atom Effects](https://recoiljs.org/docs/guides/atom-effects) API를 생각해볼수도 있습니다.

## Synchronous Example(동기 예시)

여기 user 이름을 얻기위한 간단한 동기 atom 과 selector를 예로 들어보겠습니다.

```react
const currentUserIDState = atom({
  key: 'CurrentUserID',
  default: 1,
});

const currentUserNameState = selector({
  key: 'CurrentUserName',
  get: ({get}) => {
    return tableOfUsers[get(currentUserIDState)].name;
  },
});

function CurrentUserInfo() {
  const userName = useRecoilValue(currentUserNameState);
  return <div>{userName}</div>;
}

function MyApp() {
  return (
    <RecoilRoot>
      <CurrentUserInfo />
    </RecoilRoot>
  );
}
```

## Asynchronous Example (비동기 예시)

만약 user의 이름이 쿼리 해야하는 데이터베이스에 저장되어 있었다면, `Promise`를 리턴하거나 혹은 `async` 함수를 사용하기만 하면 됩니다. 의존성에 하나라도 변경점이 생긴다면, selector는 새로운 쿼리를 재평가하고 다시 실행시킬겁니다. 그리고 결과는 쿼리가 유니크한 인풋이 있을 때에만 실행되도록 캐시됩니다.

```react
const currentUserNameQuery = selector({
  key: 'CurrentUserName',
  get: async ({get}) => {
    const response = await myDBQuery({
      userID: get(currentUserIDState),
    });
    return response.name;
  },
});

function CurrentUserInfo() {
  const userName = useRecoilValue(currentUserNameQuery);
  return <div>{userName}</div>;
}
```

Selector의 인터페이스는 동일하므로 컴포넌트에서는 selector를 사용하면서 동기 atom 상태나 파생된 selector 상태, 혹은 비동기 쿼리를 지원하는지 신경쓰지 않아도 괜찮습니다!

하지만, React 렌더 함수가 동기인데 promise가 resolve 되기 전에 무엇을 렌더 할 수 있을까요? Recoil은 보류중인 데이터를 다루기 위해 [React Suspense](https://reactjs.org/docs/concurrent-mode-suspense.html)와 함께 동작하도록 디자인되어 있습니다. 컴포넌트를 Suspense의 경계로 감싸는 것으로 아직 보류중인 하위 항목들을 잡아내고 대체하기 위한 UI를 렌더합니다.

```react
function MyApp() {
  return (
    <RecoilRoot>
      <React.Suspense fallback={<div>Loading...</div>}>
        <CurrentUserInfo />
      </React.Suspense>
    </RecoilRoot>
  );
}
```

## Error Handling (에러 다루기)

만약 요청에 에러가 있다면 어떻게 해야 할까요? Recoil selector는 컴포넌트에서 특정 값을 사용하려고 할 때에 어떤 에러가 생길지에 대한 에러를 던질 수 있습니다. 이는 React ['<ErrorBoundary>'](https://reactjs.org/docs/error-boundaries.html)로 잡을 수 있습니다. 예를 들자면:

```react
const currentUserNameQuery = selector({
  key: 'CurrentUserName',
  get: async ({get}) => {
    const response = await myDBQuery({
      userID: get(currentUserIDState),
    });
    if (response.error) {
      throw response.error;
    }
    return response.name;
  },
});

function CurrentUserInfo() {
  const userName = useRecoilValue(currentUserNameQuery);
  return <div>{userName}</div>;
}

function MyApp() {
  return (
    <RecoilRoot>
      <ErrorBoundary>
        <React.Suspense fallback={<div>Loading...</div>}>
          <CurrentUserInfo />
        </React.Suspense>
      </ErrorBoundary>
    </RecoilRoot>
  );
}
```

## Queries with Parameters (매개변수가 있는 쿼리)

가끔 파생된 상태만이 아닌 매개변수를 기반으로 쿼리를 하고싶을 때가 있을 수 있습니다.  예를 들어 컴포넌트 props를 기반으로 쿼리를 하고 싶다고 해봅시다. 이 때 [selectorFamily](https://recoiljs.org/docs/api-reference/utils/selectorFamily) helper를 사용할 수 있습니다.

```react
const userNameQuery = selectorFamily({
  key: 'UserName',
  get: userID => async () => {
    const response = await myDBQuery({userID});
    if (response.error) {
      throw response.error;
    }
    return response.name;
  },
});

function UserInfo({userID}) {
  const userName = useRecoilValue(userNameQuery(userID));
  return <div>{userName}</div>;
}

function MyApp() {
  return (
    <RecoilRoot>
      <ErrorBoundary>
        <React.Suspense fallback={<div>Loading...</div>}>
          <UserInfo userID={1}/>
          <UserInfo userID={2}/>
          <UserInfo userID={3}/>
        </React.Suspense>
      </ErrorBoundary>
    </RecoilRoot>
  );
}
```

## Data-Flow Graph

