# 타입스크립트의 필요성

---

처음 프론트엔드 공부를 시작하면서 자바스크립트의 탄생과 발전에 대하여 꽤 긴 이야기들을 흥미롭게 들었던 기억이 난다. (자바스크립트의 탄생에 대해서는 이후에 한 번 정리해보겠다.) 자바스크립트는 다른 언어들처럼 체계적으로(복잡한 구조를 가지고는 있으나) 개발된 언어라기보다는 간단하게 페이지의 인터랙션을 조정할 정도의 생각으로 만들어진 언어였다. 이랬던 언어가 인터넷의 보급과 스마트폰의 개발로 그 필요성이 절정에 달하게 되었다. 다른 언어와는 다른 탄생 배경으로 인해 자바스크립트는 '엄격한' 형태를 그다지 필요로 하지 않았다. 다른 언어와 다르게 타입을 지정해줄 필요도 없고, 그렇다고 툭하면 에러를 뱉어내지도 않는 어찌보면 순하고, 어찌보면 바보같은 언어가 되어버렸다. 자바스크립트의 이러한 특징은 코드량을 줄이는데에는 일조를 하지만 결국 디버깅을 하기 힘들어지는 건 개발자의 몫이 되었다.

> 그러면 우리도 다른 언어들처럼 타입을 명시적으로 적어주는 '엄격함'을 갖추면 되는 거 아니야?

많은 타 개발 분야에서 종사하던 개발자분들은 자바스크립트를 보면서 '이게 무슨 컴퓨터 언어야' 라고 생각을 했을지도 모르겠다. 실제로도 자바스크립트는 이전에 많이 홀대받던 언어였다. 심지어 싱글스레드로 만들어져서 느리기까지 하다. 알고리즘을 푸는데에는 속도가 느려 홀대받는다.

심지어 이렇게 '느리다'고 평가받는 언어를 이전에는 jQuery라는 라이브러리를 이용해서 사용했었다. (이전이라고 하기에는 아직까지도 널리 쓰이고 있는 라이브러리이다.) jQuery 라이브러리는 바닐라를 사용해본 사람들이라면 체감할 수 있을정도로 사용법이 쉬웠고, 다양한 함수들을 간단한 명령어들만으로도 사용할 수 있게 해주었다. 다만 라이브러리를 사용한다는 특성상 보기에 간단해보이는 코드는 실제로 몇 배의 자바스크립트 코드로 이루어져있었고, 이는 자연스레 성능을 저하시키는 원인이 되기도 했다. 또한 복잡한 함수를 직접 만들어 사용하기에도 한계가 있었다. 이를 위해서 자바스크립트 그 자체를 공부하는 사람들이 늘었고, 이제 자바스크립트를 공부하지 않고는 프론트엔드를 한다고 말할 수 없는 지경에 이르렀다.

이렇게 필요성이 대두된 자바스크립트이기에 위에서 설명했던 단점들은 '개발을 배운 개발자'들에게는 이해하기 난해한 언어가 되었다. 때문에 이를 좀 더 정돈된 형태로 사용할 수 있게 만든 것이 바로 타입스크립트이다. 고질적인 문제로 대두되었던 타입 지정 문제를 해결하는 것으로 협업에서 생길 수 있는 '잘못 전달되는 값의 타입'을 잡을 수 있게 되었고, '함수가 리턴하는 값의 타입'까지도 제대로 확인하고 에러로 잡는 것이 가능해졌다.

타입스크립트의 타입 지정은 처음 개발을 배우는 이에게는 장벽이 될 수 있지만, 그 장벽을 넘은 사람들에게는 컴퓨터 언어 자체의 생태계를 이해하고 클린한 코드를 만드는데에 일조 할 수 있게 된다.

---

## 타입스크립트 공부 강의

- 인프런 타입스크립트 강좌
- 