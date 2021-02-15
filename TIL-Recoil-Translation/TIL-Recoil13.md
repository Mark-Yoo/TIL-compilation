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

