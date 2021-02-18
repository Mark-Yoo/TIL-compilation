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

- `dangerouslyAllowMutability` - 몇 몇 경우에는 상태의 변경을 나타내지 않는 selector에 저장된 객체의 변경을 허용하는 것이 바람직할 수 있습니다. 이 옵션을 사용하여 개발모드에서 프리징 된 객체를 오버라이드 할 수 있습니다.

```react
const mySelector = selector({
  key: 'MySelector',
  get: ({get}) => get(myAtom) * 100,
});
```

### Dynamic Dependencies (동적 종속성)

읽기 전용 selector는 의존성을 바탕으로 selector의 값을 평가하는 `get` 메서드를 가지고 있습니다. 이 의존성들 중 하나라도 업데이트가 되면 selector는 재평가 됩니다. 의존성은 selector를 평가할 때에 실제로 사용한 atom이나 selector를 바탕으로 동적으로 결정됩니다. 이전 의존성의 값에 따라서 동적으로 다른 추가적인 의존성을 사용 할 수도 있습니다. Recoil은 자동적으로 최신의 data-flow-fragh를 업데이트하여 selector가 최근의 의존성의 집합만을 구독하여 업데이트 할 수 있도록 합니다.

이 예제에서 `mySelector는` `toggleState` atom에 의존하며 `selectorA` 혹은 `selectorB`는 `toggleState`의 상태에 의존합니다.

```react
const toggleState = atom({key: 'Toggle', default: false});

const mySelector = selector({
  key: 'MySelector',
  get: ({get}) => {
    const toggle = get(toggleState);
    if (toggle) {
      return get(selectorA);
    } else {
      return get(selectorB);
    }
  },
});
```

### Writable Selectors (기록 가능한 Selectors)

양방향 selector는 들어오는 값을 매개변수로 받아 이를 data-flow-graph를 따라 변경사항을 상위로 전파할 수 있습니다. 사용자가 selector를 새로운 값으로 설정하거나, 리셋할 수도 있기 때문에 들어오는 값은 selector를 대표하는 값과 같은 값이거나 리셋 동작을 대표하는 `DefaultValue` 객체입니다.

이 간단한 selector는 본질적으로 추가적인 필드르 더해 atom을 감쌉니다. 설정 및 재설정 작업을 통해서 상위의 atom으로 전달됩니다.

```react
const proxySelector = selector({
  key: 'ProxySelector',
  get: ({get}) => ({...get(myAtom), extraField: 'hi'}),
  set: ({set}, newValue) => set(myAtom, newValue),
});
```

이 selector는 데이터를 변환하므로 들어오는 값이 `DefaultValue인지` 체크해야합니다.

```react
const transformSelector = selector({
  key: 'TransformSelector',
  get: ({get}) => get(myAtom) * 100,
  set: ({set}, newValue) =>
    set(myAtom, newValue instanceof DefaultValue ? newValue : newValue / 100),
});
```

### Asynchronous Selectors

Selector는 비동기 평가 함수를 가지고 있을 수 있으며 `Promise`를 아웃풋 값에 리턴합니다. 더 많은 정보는 다음의 [가이드](https://recoiljs.org/docs/guides/asynchronous-data-queries)를 참고하여 주십시오.

```react
const myQuery = selector({
  key: 'MyQuery',
  get: async ({get}) => {
    return await myAsyncQuery(get(queryParamState));
  }
});
```

### Example (Synchronous) (동기 예제)

```react
import {atom, selector, useRecoilState, DefaultValue} from 'recoil';

const tempFahrenheit = atom({
  key: 'tempFahrenheit',
  default: 32,
});

const tempCelsius = selector({
  key: 'tempCelsius',
  get: ({get}) => ((get(tempFahrenheit) - 32) * 5) / 9,
  set: ({set}, newValue) =>
    set(
      tempFahrenheit,
      newValue instanceof DefaultValue ? newValue : (newValue * 9) / 5 + 32
    ),
});

function TempCelsius() {
  const [tempF, setTempF] = useRecoilState(tempFahrenheit);
  const [tempC, setTempC] = useRecoilState(tempCelsius);
  const resetTemp = useResetRecoilState(tempCelsius);

  const addTenCelsius = () => setTempC(tempC + 10);
  const addTenFahrenheit = () => setTempF(tempF + 10);
  const reset = () => resetTemp();

  return (
    <div>
      Temp (Celsius): {tempC}
      <br />
      Temp (Fahrenheit): {tempF}
      <br />
      <button onClick={addTenCelsius}>Add 10 Celsius</button>
      <br />
      <button onClick={addTenFahrenheit}>Add 10 Fahrenheit</button>
      <br />
      <button onClick={reset}>>Reset</button>
    </div>
  );
}
```

### Example (Asynchronous) (비동기 예제)

```react
import {selector, useRecoilValue} from 'recoil';

const myQuery = selector({
  key: 'MyDBQuery',
  get: async () => {
    const response = await fetch(getMyRequestUrl());
    return response.json();
  },
});

function QueryResults() {
  const queryResults = useRecoilValue(myQuery);

  return (
    <div>
      {queryResults.foo}
    </div>
  );
}

function ResultsSection() {
  return (
    <React.Suspense fallback={<div>Loading...</div>}>
      <QueryResults />
    </React.Suspense>
  );
}
```

더 복잡한 예제를 확인하시려면 다음의 [가이드](https://recoiljs.org/docs/guides/asynchronous-data-queries)를 참고해주세요