# atom(options)

atom은 Recoil의 상태를 대표합니다. `atom()` 함수는 쓸 수 있는(writable) `RecoilState` 객체를 반환합니다.

```react
function atom<T>({
  key: string,
  default: T | Promise<T> | RecoilValue<T>,

  effects_UNSTABLE?: $ReadOnlyArray<AtomEffect<T>>,

  dangerouslyAllowMutability?: boolean,
}): RecoilState<T>
```

- `key` - atom을 내부적으로 식별하기 위해서 사용되는 고유한 문자열입니다. 이 문자열은  전체 어플리케이션의 다른 atom과 selector와 관련하여 고유해야합니다.

- `default` - atom 혹은 Promise, 또다른 atom, 혹은 selector의 초기값은 같은 타입의 값을 대표합니다.
- `effects_UNASTABLE` - atom을 위한 [Atom Effects](https://recoiljs.org/docs/guides/atom-effects)의 부가적인 배열입니다.

- `dangerouslyAllowMutability` - 몇 몇 케이스에서 상태 변화를 나타내지 않는 atom에 저장된 객체의 변형을 허용하는 것이 바람직할 수 있습니다. 이 옵션은 개발모드에서 프리징된 객체를 오버라이드 하기 위해 사용하십시오.

---

Recoil은 atom 상태의 변화를 관리하여 그 atom을 구독하는 컴포넌트에 리렌더링을 언제 알려야하는지 알고 있으므로, 아래에 나열된 hooks를 사용하여 atom의 상태를 변경해야합니다. 만약 atom에 저장된 객체가 직접적으로 변형됐다면, 이는 이 방법을 우회하여 상태의 변경을 구독중인 컴포넌트에 제대로 알리지 않은 채로 상태 변경을 일으킬 수 있습니다. 버그를 찾는 것을 돕기위해 개발모드에서 Recoil은 atom에 저장된 객체를 프리징 시킵니다.

대부분의 경우, atom과 상호작용을 하기 위해서 다음의 hooks들을 사용하게 됩니다:

- `useRecoilState()`: 이 hook은 atom을 읽고 쓰기를 모두 가능하게하고자 사용됩니다. 이 hook은 컴포넌트를 atom에 구독시킵니다.
- `useRecoilValue()`: 이 hook은 atom을 읽기만 가능하게 만들 때에 사용됩니다. 이 hook은 컴포넌트를 atom에 구독시킵니다.