# border-box의 특성에 대하여

---

보통 우리들이 만드는 상자들은 보통 content-box 속성을 기본으로 가지고 있다. content-box의 경우, 기본적으로 padding과 border를 포함하지 않고 content 부분만 독자적인 width와 height를 갖게된다. 이 때문에 css를 적용하는 도중 레이아웃이 망가져버리는 상상조차 하기 싫은 일들이 생기기도 한다.

이 때문에 애초에 제작할 때에 box-sizing을 아예 border-box로 변경하여 그런 일들이 생기지 않게 할 수도 있다. (무엇이든 정답은 없다. 필요에 따라 다양하게 사용하는 것이 맞다.)

border-box는 content의 범위와 padding, border까지 포함되어 계산된다. width와 height를 한 번 정하면 대부분 이 레이아웃이 망가질 일은 많지 않다는 것.

하지만 이러한 border-box도 레이아웃이 망가지는 경우가 있는데 padding이 content 영역을 완전히 덮을 정도로 커진다면 초과하는 padding의 수치만큼 border-box도 크기가 커질 수밖에 없다. 이러한 부분을 가끔 제대로 파악하기 힘든 이유는 content 영역은 0에 수렴하면서 작아지지만 마이너스가 될 수는 없기 때문에 content는 눈에 계속 보일 수밖에 없고, border-box를 제대로 이해하지 못했다면 border-box가 왜 자꾸 커지는걸까에 대한 고민을 할 수 밖에 없다.

> content-box와 border-box를 제대로 알고 이용하면 그 특성들도 장점이 된다.