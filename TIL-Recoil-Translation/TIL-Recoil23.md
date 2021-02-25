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

스냅샷은 atom 상태에 관련하여 읽기 전용입니다. 이들은 atom 상태를 읽고 selector의 파생된 상태를 평가하기 위해서 사용될 수 있습니다. `getLoadable()`은 이 스냅샷의 atom 혹은 selector의 상태와 함께 Loadable을 제공합니다.