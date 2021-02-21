# useRecoilCallback(callback, deps)

이 hook은 [*`useCallback()`*](https://reactjs.org/docs/hooks-reference.html#usecallback)과 비슷합니다만 Recoil 상태(state)에서 callback이 동작하도록 API를 제공합니다. 이 hook은 비동기적으로 현재의 Recoil 상태를 업데이트하는 기술과 Recoil 상태의 읽기 전용 [`Snapshot`](/docs/api-reference/core/Snapshot) 에 접근할 수 있는 callback을 구축하기 위해 사용될 수 있습니다.

이 hook을 사용하기 위한 동기로는 다음을 포함할 수 있습니다:

- atom 혹은 selector가 업데이트 될 때 리렌더링하기 위해 React 컴포넌트를 구독하지 않고 비동기적으로 Recoil 상태를 읽기 위해 사용하기
- 렌더링 할 때에 수행하고 싶지 않은 비동기 동작에 대한 값비싼 조회를 연기할 때
- Recoil 상태에 