# useRecoilState(state)

첫 요소가 상태의 값이며, 두번째 요소가 호출되었을 때 주어진 값을 업데이트하는 setter 함수인 튜플을 리턴합니다.

이 hook은 암묵적으로 주어진 상태에 컴포넌트를 구독합니다.

---

```react
function useRecoilState<T>(state: RecoilState<T>): [T, SetterOrUpdater<T>];

type SetterOrUpdater<T> = (T | (T => T)) => void;
```

- `state`: atom 혹은 *쓰기가능*한 selector. 읽기 전용 selector가 `get`만 가지고 있을 때, *쓰기가능*한 selector는  `get` 과  `set` 를 정의에 가지고 있습니다.

이 API는 기본값 대신 React Recoil 상태를 인수로 받는 다는 점만 빼면 `useState()` hook과 비슷합니다. 상태와 setter 함수의 최신 값의 튜플을 리턴합니다. setter 함수는 새로운 값을 인수로 받거나 이전 값을 매개변수로 받는 updater 함수를 취합니다.

---

