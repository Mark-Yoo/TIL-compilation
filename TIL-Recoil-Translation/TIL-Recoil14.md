# selector(options)

Selector는 Recoil에서 함수 혹은  **파생된 상태** 를 대표합니다. selector를 부수효과가 없는으며 언제나 주어진 의존성 값들에 같은 값을 리턴하는 "멱등함" 혹은 "순수 함수"과 비슷하다고 생각할 수도 있습니다. 만약 `get` 함수만 제공되었다면, selector는 읽기 전용에 RecoilValueReadOnly 객체를 반환할 것이며. `set` 함수까지 제공된다면, 쓰기 가능한 RecoilState 객체를 반환할 것입니다.

