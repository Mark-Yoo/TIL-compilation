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

atom은 Recoil에 포함된 상태 조각을 나타냅니다. atom은 앱에 의해서 `<RecoilRoot>`마다 생성되고 등록됩니다. 하지만 만약 상태가 전역이 아니라면 어떻게 될까요? 상태가 컨트롤의 특정 인스턴스 혹은 특정 요소와 연결되어 있다면 어떻게 될까요? 예를 들어 앱이 동적으로 요소를 추가할 수 있고 각 요소가 위치와 같은 상태를 갖는 UI 프로토타이핑 도구일수도 있습니다. 이상적으로 각 요소는 요소만의 상태의 atom을 갖게 됩니다.

