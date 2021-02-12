# Atom Effects

Atom Effects는 부수효과를 통제하고 Recoil의 atom을 초기화 하기 위한 새로운 실험적 API입니다. Atom Effects는 state persistence(상태 지속성), state synchronization(상태 동기화), managing history(히스토리 관리), logging(로깅) 등등 유용한 어플리케이션을 다양하게 가지고 있습니다. Atom Effects는 atom 정의의 일부로 정의되므로 각 atom은 자체적인 정책들을 지정하고 구성할 수 있습니다. 이 API는 아직 진화중이며, 그러므로 _UNSTABLE(불완전)로 마크되어 있습니다.

---

## IMPORTANT NOTE

이 API는 현재 개발중이며 변경점이 생길 수 있습니다.

---

*Atom Effect*는 다음의 정의를 따르는 함수입니다.

```react
type AtomEffect<T> = ({
  node: RecoilState<T>, // A reference to the atom itself
  trigger: 'get' | 'set', // The action which triggered initialization of the atom

  // Callbacks to set or reset the value of the atom.
  // This can be called from the atom effect function directly to initialize the
  // initial value of the atom, or asynchronously called later to change it.
  setSelf: (
    | T
    | DefaultValue
    | Promise<T | DefaultValue> // Only allowed for initialization at this time
    | ((T | DefaultValue) => T | DefaultValue),
  ) => void,
  resetSelf: () => void,

  // Subscribe to changes in the atom value.
  // The callback is not called due to changes from this effect's own setSelf().
  onSet: (
    (newValue: T | DefaultValue, oldValue: T | DefaultValue) => void,
  ) => void,

}) => void | () => void; // Optionally return a cleanup handler
```

Atom Effects는 effects_UNSTABLE 옵션을 통해서 atoms에 연결되어 있습니다. 각각의 atom은 atom이 초기화 될 때 우선 순위에 따라 호출되는 atom effect 함수들의 배열을 참조할 수 있습니다. Atom은 `<RecoilRoot>` 내에서 처음 사용될 때에 초기화되지만, 만약 사용되지 않거나 정리되어 없어졌을 때 다시 초기화 될 수 있습니다. Atom Effect 함수는 cleanup의 부수효과를 관리하기 위해서 선택적 cleanup 핸들러를 리턴할 수도 있습니다.

```react
const myState = atom({
  key: 'MyKey',
  default: null,
  effects_UNSTABLE: [
    () => {
      ...effect 1...
      return () => ...cleanup effect 1...;
    },
    () => { ...effect 2... },
  ],
});
```

[Atom families](https://recoiljs.org/docs/api-reference/utils/atomFamily)는 매개변수화 혹은 비-매개변수화된 효과들 역시 지원합니다.

```react
const myStateFamily = atomFamily({
  key: 'MyKey',
  default: null,
  effects_UNSTABLE: param => [
    () => {
      ...effect 1 using param...
      return () => ...cleanup effect 1...;
    },
    () => { ...effect 2 using param... },
  ],
});
```

### Compared to React Effects (React Effect와 비교하기)

Atom Effects는 대부분의 경우 리액트의 `useEffect()`로 대체될 수 있습니다. 그러나 atom의 집합은 리액트 컨텍스트의 외부에서 생성되며, 특히 동적으로 생성된 atom의 경우 리액트 컴포넌트 내에서 효과를 관리하기 어려울 수 있습니다. 초기 atom 값을 초기화하거나 서버 사이드 렌더링(SSR)과 함께 사용될 수 없습니다. atom effects를 사용하는 것은 effects와 atom 정의를 함께 배치하게 합니다.

```react
const myState = atom({key: 'Key', default: null});

function MyStateEffect(): React.Node {
  const [value, setValue] = useRecoilState(myState);
  useEffect(() => {
    // Called when the atom value changes
    store.set(value);
    store.onChange(setValue);
    return () => { store.onChange(null); }; // Cleanup effect
  }, [value]);
  return null;
}

function MyApp(): React.Node {
  return (
    <div>
      <MyStateEffect />
      ...
    </div>
  );
}
```

### Compared to Snapshots (스냅샵과 비교하기)

[Snapshot hooks](https://recoiljs.org/docs/api-reference/core/Snapshot#hooks) API도 atom 상태의 변화를 감시할 수 있으며 [`<RecoilRoot>`](https://recoiljs.org/docs/api-reference/core/RecoilRoot)의 initializeState prop은 초기 렌더링을 위한 값을 초기화 할 수 있습니다. 그러나 이 API들은 모든 상태의 변화를 모니터링하고 동적 atom, 특히 atom family를 관리하는 데에는 어색 할 수 있습니다. Atom Effects를 사용하면 atom 정의와 함께 atom 별로 부수효과가 정의될 수 있으며 여러 정책들을 쉽게 작성할 수 있습니다.

## Logging Example (로깅 예시)

atom effects를 사용하는 간단한 예시는 특정 atom의 상태 변화을 기록하는 것입니다.

```react
const currentUserIDState = atom({
  key: 'CurrentUserID',
  default: null,
  effects_UNSTABLE: [
    ({onSet}) => {
      onSet(newID => {
        console.debug("Current user ID:", newID);
      });
    },
  ],
});
```

## History Example (히스토리 예시)

로깅의 더 복잡한 예시는 변화의 히스토리를 유지할 수 있습니다. 이 예시는 특정 변화를 원상태로 되돌리는 콜백 핸들러를 사용하여 상태의 변경 내역 큐를 유지하는 효과를 제공합니다:

```react
const history: Array<{
  label: string,
  undo: () => void,
}> = [];

const historyEffect = name => ({setSelf, onSet}) => {
  onSet((newValue, oldValue) => {
    history.push({
      label: `${name}: ${JSON.serialize(oldValue)} -> ${JSON.serialize(newValue)}`,
      undo: () => {
        setSelf(oldValue);
      },
    });
  });
};

const userInfoState = atomFamily({
  key: 'UserInfo',
  default: null,
  effects_UNSTABLE: userID => [
    historyEffect(`${userID} user info`),
  ],
});
```

## State Synchronization Example (상태 동기화 예제)

atom을 원격 데이터베이스, 로컬 스토리지 등 처럼 다른 상태의 로컬 캐시 값으로 사용하는 것은 유용할 수 있습니다. store의 값을 얻기위해 `default`프로퍼티와 selector를 이용해 atom의 기본값을 설정해 줄 수 있습니다. 그러나 이는 일회성 조회 일 뿐입니다. store의 값이 변경된다면 atom의 값은 변경되지 않습니다. effects와 함께라면, store가 변경될 때마다  store를 구독하고 atom의 값을 업데이트 할 수 있습니다. effect에서 `setSelf()`를 호출하는 것은 그 값으로 atom을 초기화하고 초기 렌더링에 이용될 것입니다. Atom이 리셋되면, 초기화된 값이 아니라 `default`값으로 돌아갈겁니다.

```react
const syncStorageEffect = userID => ({setSelf, trigger}) => {
  // Initialize atom value to the remote storage state
  if (trigger === 'get') { // Avoid expensive initialization
    setSelf(myRemoteStorage.get(userID)); // Call synchronously to initialize
  }

  // Subscribe to remote storage changes and update the atom value
  myRemoteStorage.onChange(userID, userInfo => {
    setSelf(userInfo); // Call asynchronously to change value
  });

  // Cleanup remote storage subscription
  return () => {
    myRemoteStorage.onChange(userID, null);
  };
};

const userInfoState = atomFamily({
  key: 'UserInfo',
  default: null,
  effects_UNSTABLE: userID => [
    historyEffect(`${userID} user info`),
    syncStorageEffect(userID),
  ],
});
```

## Write-Through Cache Example (연속 기입 캐시 예제)

atom 값을 원격 스토리지와 양방향으로 동기화 할 수도 있으므로 서버의 변경점이 atom 값을 업데이트하고, 로컬 atom의 변경점은 서버에 다시 기록합니다. effect는 피드백 루프를 피하기 위해서, 해당 effect의 `setSelf()` 를 통해서 변경될 때 `onSet()`핸들러를 호출하지 않습니다.

```react
const syncStorageEffect = userID => ({setSelf, onSet, trigger}) => {
  // Initialize atom value to the remote storage state
  if (trigger === 'get') { // Avoid expensive initialization
    setSelf(myRemoteStorage.get(userID)); // Call synchronously to initialize
  }

  // Subscribe to remote storage changes and update the atom value
  myRemoteStorage.onChange(userID, userInfo => {
    setSelf(userInfo); // Call asynchronously to change value
  });

  // Subscribe to local changes and update the server value
  onSet(userInfo => {
    myRemoteStorage.set(userID, userInfo);
  });

  // Cleanup remote storage subscription
  return () => {
    myRemoteStorage.onChange(userID, null);
  };
};
```

## Local Storage Persistence (로컬 스토리지 지속성)

Atom Effects는 atom 상태를 브라우저 로컬 스토리지에서 유지하기 위해서 사용될 수 있습니다. 로컬 스토리지는 동기식이므로 데이터를 `async/await` 혹은 `Promise` 없이 직접 받아올 수 있습니다.

다음의 예제 설명을 위해서 단순화 되었으며 모든 케이스를 포함하지는 않습니다.

```react
const localStorageEffect = key => ({setSelf, onSet}) => {
  const savedValue = localStorage.getItem(key)
  if (savedValue != null) {
    setSelf(JSON.parse(savedValue));
  }

  onSet(newValue => {
    if (newValue instanceof DefaultValue) {
      localStorage.removeItem(key);
    } else {
      localStorage.setItem(key, JSON.stringify(newValue));
    }
  });
};

const currentUserIDState = atom({
  key: 'CurrentUserID',
  default: 1,
  effects_UNSTABLE: [
    localStorageEffect('current_user'),
  ]
});
```

## Asynchronous Storage Persistence (비동기적 스토리지 지속성)

지속되는 데이터는 비동기적으로 돌려받아야 한다면 `setSelf()` 함수에서 Promise를 사용하거나 비동기적으로 호출할 수 있습니다.

아래에서는 `AsyncLocalStorage` 혹은 `localForage`를 비동기 store의 예시로 사용해 볼 보겠습니다.

### Initialize with Promise (Promise로 초기화하기)

Promise와 `setSelf()`를 동기적으로 호출하면,  `<RecoilRoot />` 내부의 구성요소를 `<Suspense />` 구성요소로 감싸 Recoil이 지속 된 값을 로드 할 때까지 기다리는 동안 fallcack을 보여주는 것이 가능합니다. `<Suspense>`는 `setSelf()`에 제공된 `setSelf()`가 resolve 될 때까지 fallback을 보여줍니다.