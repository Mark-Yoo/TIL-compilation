# Recoil's Motivation

---

호환성과 간소화를 위해서 외부의 전역 상태보다 리액트의 빌트인 상태 관리 능력을 사용하는 것이 최선이라고 할 수 있을 것이다. 하지만 리액트는 몇가지 제한이 있다.

- 컴포넌트의 상태가 오직 공통 조상에게만 보내는 것으로 공유가 가능한 것, 하지만 이러한 특징은 곧 커다란 컴포넌트 트리를 포함할 수 있다는 것으로 리렌더링으로 연결될 수 있다는 의미이기도 하다.
- 컨텍스트는 고유한 소비자들들이 각각 가질 수 있는 무한한 값의 집합이 아닌 단 하나의 값 만을 저장할 수 있다.
- 이 두가지의 특징은 트리의 최상부(상태가 있어야 하는 곳)를 트리의 잎사귀들(상태가 사용되는 곳)로부터 분리하기 어렵게 만든다

우리는 이러한 문제를 API와 시맨틱함을 지키면서, 또한 최대한 '리액티쉬'하게 해결하고 싶었다.

Recoil은 방향성 그래프가 트리에 직교하는 것뿐만 아니라 본질적으로 리액트 트리에 속하는 것을 정의한다고 할 수 있다. 상태는 이 그래프의 루트(우리들이 atoms라고 부르는 것)에서부터 순수 함수(우리들이 선택자라 부르는 그것)를 지나 컴포넌트에 이르기까지의 흐름을 바꾼다. 이는 이러한 접근을 따른다:

- 공유된 상태가 리액트의 로컬 상태로서 심플한 get/set 인터페이스만을 갖는, 보일러 플레이트가 필요없는 API를 가지고 있다.(하지만 필요하다면 리듀서 등으로 캡슐화 할 수 있다. )

- 현재 공존하고 있는 모드들과 앞으로 사용 가능하게 될 리액트의 새로운 요소들을 호환하게 될 상황들까지 고려한다.
- 상태의 정의는 증가와 분산이다. 가능한한 코드를 분리한다.
- 상태는 상태를 사용하고 있는 컴포넌트를 수정하지 않고도 파생된 데이터로 교체될 수 있다.