# selector(options)

Selector는 Recoil에서 함수 혹은  **파생된 상태** 를 대표합니다. selector를 부수효과가 없는으며 언제나 주어진 의존성 값들에 같은 값을 리턴하는 "멱등함" 혹은 "순수 함수"과 비슷하다고 생각할 수도 있습니다. 만약 `get` 함수만 제공되었다면, selector는 읽기 전용에 RecoilValueReadOnly 객체를 반환할 것이며. `set` 함수까지 제공된다면, 쓰기 가능한 RecoilState 객체를 반환할 것입니다.

Recoil은 언제 컴포넌트가 리렌더링을 위해서 selector를 구독하는지 알리기 위해서 atom과 selector 상태 변화를 다룹니다. 만약 selector의 객체값이 직접적으로 변경된다면 이를 우회하고 구독중인 컴포넌트들에 제대로 알리는 것을 피하게 됩니다. 버그를 찾는 것을 돕기 위해 Recoil은 개발모드에서 selector 값 객체들을 프리징 시킵니다.

```react
function selector<T>({
  key: string,

  get: ({
    get: GetRecoilValue
  }) => T | Promise<T> | RecoilValue<T>,

  set?: (
    {
      get: GetRecoilValue,
      set: SetRecoilState,
      reset: ResetRecoilState,
    },
    newValue: T | DefaultValue,
  ) => void,

  dangerouslyAllowMutability?: boolean,
})
```

```react
type ValueOrUpdater<T> = T | DefaultValue | ((prevValue: T) => T | DefaultValue);
type GetRecoilValue = <T>(RecoilValue<T>) => T;
type SetRecoilState = <T>(RecoilState<T>, ValueOrUpdater<T>) => void;
type ResetRecoilState = <T>(RecoilState<T>) => void;
```

- `key` - 내부적으로 atom을 식별하기 위해 사용되는 고유한 문자열. 이 문자열은 전체 어플리케이션의 다른 atom과 selector들에 대해서 고유해야합니다. 지속성을 위해서 사용된다면 실행 간에 안정적이어야합니다.
- `get` - 파생된 상태를 위한 값을 평가하는 함수. 직접적으로, 혹은 비동기적으로 값을 리턴할 수 있습니다. Promise 혹은 다른 atom 혹은 selector는 같은 타입을 대표합니다. 다음의 프로퍼티들을 포함한 객체를 첫번째 매개변수로 넘겨줍니다.
  - `get` - 다른 atom/selector에서 값을 받아오기 위해 사용되는 함수. 이 함수로 전달된 모든 atom/selector는 암암리에 selector를 위한 의존성 리스트에 더해집니다. selector의 의존성들에 변화가 생긴다면 selector가 재평가를 할 것입니다.
- `set?` - 만약 이 프로퍼티가 설정된다면 selector는 **쓰기가능(writable)**한 상태를 리턴합니다. 콜백 객체를 첫번째 매개변수와 새롭게 들어오는 값으로 전달하는 함수입니다. 들어오는 값은 T 타입의 값이거나, 만약 유저가 selector를 리셋한다면 DefaultValue 타입의 객체일 수 있습니다. 콜백은 다음을 포함합니다:
  - `get` - 다른 atom/selector에서 값을 받아오기 위한 함수. 이 함수는 주어진 atom/selector에 selector를 구독시키지 않습니다.
  - `set` - 상위의 Recoil 상태의 값을 세트하기 위해서 사용되는 함수. 첫번째 매개변수는 Recoil 상태이며 두번째 매개변수는 새로운 값입니다. 새로운 값은 updater 함수이거나 재설정 작업을 전달하기 위한 DefaultValue 객체일 수 있습니다.

