# atomFamily(options)

쓰기 가능한 `RecoilState` [atom](/docs/api-reference/core/atom) 을 리턴하는 함수를 리턴합니다.

---

```jsx
function atomFamily<T, Parameter>({
  key: string,

  default:
    | RecoilValue<T>
    | Promise<T>
    | T
    | (Parameter => T | RecoilValue<T> | Promise<T>),

  effects_UNSTABLE?:
    | $ReadOnlyArray<AtomEffect<T>>
    | (P => $ReadOnlyArray<AtomEffect<T>>),

  dangerouslyAllowMutability?: boolean,
}): Parameter => RecoilState<T>
```

- `key` - 내부적으로 atom을 식별하기 위해 사용되는 고유한 문자열. 이 문자열은 전체 어플리케이션에서 다른 atom과 selector에 관해서 고유해야합니다.

- `default` - atom의 초기값. 직접적 값이거나 기본값을 나타내는 `RecoilValue` 혹은 `Promise`, 혹은 기본값을 가져오는 함수. 콜백 함수는 `atomFamily` 함수가 호출될 때 사용된 파라미터의 복사본을 넘깁니다.

- `effects_UNSTABLE` - [Atom Effects](/docs/guides/atom-effects)의 추가적인 배열, 혹은 family 파라미터를 기반으로 한 배열을 얻기 위한 콜백

- `dangerouslyAllowMutability` -  Recoil은 atom의 상태 변화에 따라 atom을 사용하여 리렌더링하는 컴포넌트에 언제 알려야하는지 알 수 있습니다. atom의 값이 변형되었다면, 이를 우회하여 구독중인 컴포넌트에 알리지 않고 상태가 변경할 수 있습니다. 이러한 상황을 막기위해 저장된 모든 모든 값은 고정됩니다. 몇 몇 경우에 따라서는 이 옵션을 사용하여 이를 재정의 할 수 있습니다.

---

atom은 Recoil에 포함된 상태 조각을 나타냅니다. atom은 앱에 의해서 `<RecoilRoot>`마다 생성되고 등록됩니다. 하지만 만약 상태가 전역이 아니라면 어떻게 될까요? 상태가 컨트롤의 특정 인스턴스 혹은 특정 요소와 연결되어 있다면 어떻게 될까요? 예를 들어 앱이 동적으로 요소를 추가할 수 있고 각 요소가 위치와 같은 상태를 갖는 UI 프로토타이핑 도구일수도 있습니다. 이상적으로 각 요소는 요소만의 상태의 atom을 갖게 됩니다. Memoization 패턴을 통해 직접 실행할 수 있지만, Recoil이 이러한 패턴을 `atomFamily` 유틸리티와 함께 제공합니다. Atom Family는 atom의 모음을 나타냅니다. `atomFamily`를 호출하면 넘겨준 매개변수를 바탕으로  `RecoilState` atom을 제공하는 함수를 반환합니다.

`atomFamily`는 기본적으로 매개 변수에서 atom으로의 맵핑을 제공합니다. `atomFamily`에 대한 단일 키만 제공하면 각 기본 atom에 대한 고유한 키가 생성됩니다. 이 atom 키는 지속성을 위해서 사용될 수 있으므로 어플리케이션의 실행 전반에 걸쳐 안정적이어야 합니다. 매개 변수는 다른 호출 사이트에서도 생성 될 수 있으며 동등한 매개 변수가 동일한 기본 atom을 사용하는 것을 원합니다. 따라서 `atomFamily` 매개 변수에 대해 참조의 동일함 대신 값의 동일함이 사용됩니다. 이는 매개 변수로 사용할 수 있는 타입에 제한을 부과합니다. `atomFamily`는 원시 타입이나 배열 혹은 배열, 객체, 원시 타입을 가진 객체를 허용합니다.

## Example

```jsx
const elementPositionStateFamily = atomFamily({
  key: 'ElementPosition',
  default: [0, 0],
});

function ElementListItem({elementID}) {
  const position = useRecoilValue(elementPositionStateFamily(elementID));
  return (
    <div>
      Element: {elementID}
      Position: {position}
    </div>
  );
}
```

`atomFamily()`는 간단한 `atom()`과 거의 동일한 옵션을 받습니다. 그러나 기본갑 역시 매개변수화 할 수 있습니다. 이는 매개변수 값을 받아 실제 기본 값을 반환하는 함수를 제공할 수 있다는 의미입니다. 예를 들자면:

```jsx
const myAtomFamily = atomFamily({
  key: ‘MyAtom’,
  default: param => defaultBasedOnParam(param),
});
```



