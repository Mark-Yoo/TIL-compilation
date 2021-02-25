# class Snapshot

Snapshot 객체는 Recoil atom의 상태의 변경불가능한 스냅샷을 나타냅니다. 전역 Recoil 상태를 관찰, 검사, 관리하기 위한 API를 표준화 하기 위한 것입니다. 이는 개발툴, 전역 상태 동기화, 히스토리 탐색 등에 유용합니다.

```jsx
class Snapshot {
  // Accessors to inspect snapshot state
  getLoadable: <T>(RecoilValue<T>) => Loadable<T>;
  getPromise: <T>(RecoilValue<T>) => Promise<T>;

  // API to transform snapshots for transactions
  map: (MutableSnapshot => void) => Snapshot;
  asyncMap: (MutableSnapshot => Promise<void>) => Promise<Snapshot>;

  // Developer Tools API
  getID: () => SnapshotID;
  getNodes_UNSTABLE: ({
    isModified?: boolean,
  } | void) => Iterable<RecoilValue<mixed>>;
  getInfo_UNSTABLE: <T>(RecoilValue<T>) => {...};
}

function snapshot_UNSTABLE(initializeState?: (MutableSnapshot => void)): Snapshot
```

## Obtaining Snapshots

### Hooks

Recoil은 다음의 hook을 현재의 상태를 기반으로 스냅샷을 얻기 위해 제공합니다:

- [`useRecoilCallback()`](/docs/api-reference/core/useRecoilCallback) - 스냅샷에 비동기 엑세스
- [`useRecoilSnapshot()`](/docs/api-reference/core/useRecoilSnapshot) - 스냅샷에 동기 엑세스
- [`useRecoilTransactionObserver_UNSTABLE()`](/docs/api-reference/core/useRecoilTransactionObserver) - 모든 상태 변경에 대해서 Snapshot을 구독

### Building a Snapshot

선택적 초기화 함수를 허용하는 `snapshot_UNSTABLE()` 팩토리를 사용하여 새로운 스냅샷을 빌드 할 수도 있습니다. 이는 React context 외부의 selector의 [테스트](/docs/guides/testing)와 평가에 사용될 수 있습니다.

## Reading Snapshots

스냅샷은 atom 상태에 관련하여 읽기 전용입니다. 이들은 atom 상태를 읽고 selector의 파생된 상태를 평가하기 위해서 사용될 수 있습니다. `getLoadable()`은 이 스냅샷의 atom 혹은 selector의 상태와 함께 Loadable을 제공합니다. `getPromise()` 메서드는 정적 atom 상태를 기반으로 하는 값을 확인 하기 위해 비동기 selector의 평가된 값을 대기하기 위해 사용될 수 있습니다.

### Example

```jsx
function MyComponent() {
  const logState = useRecoilCallback(({snapshot}) => () => {
    console.log("State: ", snapshot.getLoadable(myAtom).contents);

    const newSnapshot = snapshot.map(({set}) => set(myAtom, 42));
  });
}
```

## Transforming Snapshots

스냅샷을 변경하고 싶은 경우가 있을 수 있습니다. 스냅샷은 변경이 불가능하지만 변환 집합을 사용하여 새로운 변경불가능한 스냅샷으로 스냅샷 자신을 매핑하는 방법이 있습니다. 매핑 메서드는 콜백을 통해 변경되며 궁극적으로 매핑 작업에서 리턴되는 새로운 스냅샷이 될 MutableSnapshot을 전달받은 콜백을 받습니다.

```jsx
class MutableSnapshot {
  set: <T>(RecoilState<T>, T | DefaultValue | (T => T | DefaultValue)) => void;
  reset: <T>(RecoilState<T>) => void;
}
```

`set()` 과 `reset()`은 쓰기 가능한 selector의 set 프로퍼티에 제공된 콜백과 같은 시그니쳐를 가집니다. 하지만 현재 상태가 아닌 새로운 스냅샷에만 영향을 줍니다.

## Going to a Snapshot

다음의 hook은 현재 Recoil 상태를 제공된 `Snapshot`으로 네비게이트 할 수 있습니다.

- [`useGotoRecoilSnapshot()`](/docs/api-reference/core/useGotoRecoilSnapshot) - 현재의 상태를 Snapshot에 일치하게 업데이트

## Developer Tools

스냅샷은 개발자 툴을 빌드하거나 Recoil을 이용한 디버깅 기능에 유용하게 사용할 수 있는 몇 가지 메서드를 제공합니다. 이 API는 아직 발전 중이므로 초기 개발 도구에서 작업 할 때에 `_UNSTABLE`로 마크됩니다.

### Snapshot IDs

커밋된 각각의 상태 혹은 변경된 스냅샷은 `getID()`를 통해 얻을 수 있는 고유한 불투명 버전의 ID를 갖습니다. 이는 `useGotoRecoilSnapshot()`을 통해 이전 스냅샷으로 돌아갔을 때 이를 감지하기 위해서 사용할 수 있습니다.

### Enumerate Atoms and Selectors

`getNodes_UNSTABLE()` 메서드는 이 스냅샷에서 사용된 모든 atom과 selector를 나열하는데에 사용할 수 있습니다. Atom, selector, 그리고 families는 언제든 생성될 수 있으나, 실제로 사용되었을 때에만 스냅샷에 나타납니다. Atom과 selector는 더 이상 사용되지 않을 경우 후속 상태 스냅샷에서 제거될 수 있습니다.

선택적 `isModified` 플래그는 마지막 트랜잭션 이후 수정 된 atom만 리턴 할 수 있도록 지정할 수 있습니다.