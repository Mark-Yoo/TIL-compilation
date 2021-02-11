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

Snapshot hooks API도 atom 상태의 변화를 감시할 수 있으며 `<RecoilRoot`의 initializeState prop은 초기 렌더링을 위한 값을 초기화 할 수 있습니다.