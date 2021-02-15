# <RecoilRoot ...props />

atom이 값을 갖는 컨텍스트를 제공합니다. Recoil hooks를 사용하는 컴포넌트의 조상이어야합니다. 여러 root가 공존할 수 있습니다; atom은 각각의 root 내에서 고유한 값을 갖습니다. 만약 중첩되어있다면 가장 안쪽의 root는 바깥쪽의 root를 완전히 마스킹합니다.

---

**Props**:

- initializeState? : (MutableSnapshot => void)
  - [MutableSnapshot](https://recoiljs.org/docs/api-reference/core/Snapshot#transforming-snapshots)을 받아 `<RecoilRoot>`atom 상태를 [초기화](https://recoiljs.org/docs/api-reference/core/Snapshot#state-initialization)하는 부가적인 함수입니다. 초기 렌더의 상태를 셋업하고, 이는 후속 상태 변경 혹은 비동기 초기화를 위한 것이 아닙니다. 비동기 상태 변환을 위해서 `useSetRecoilState()` 혹은 `useRecoilCallback()`과 같은 hook을 사용할 수 있습니다.

---

`<RecoilRoot>`는 atom 상태의 독립 providers/stores를 나타냅니다. selector 캐시와 같은 캐시는 root 사이에 공유될 수 있습니다. Selector 평가는 캐싱 혹은 로깅을 제외하고 멱등해야하므로 이는 문제가 되지는 않습니다. 하지만 관찰이 가능하거나 중복되는 쿼리가 root를 걸쳐 캐시 될 수 있습니다.

### Example

```react
import {RecoilRoot} from 'recoil';

function AppRoot() {
  return (
    <RecoilRoot>
      <ComponentThatUsesRecoil />
    </RecoilRoot>
  );
}
```

