# Angular directives와 life cycle

---

언제나 인터뷰는 나의 부족한 부분을 드러내고 내 자신에게 실망하게 만든다. 그래도 모자란 부분을 알았다는 걸로 발전의 기회를 얻었으니 아픈만큼 더 성장한다는게 맞는 말 같다.

## Angular Directives

Angular에서 directive는 DOM element의 외형을 바꾸거나 동작을 바꾼다.

Angular에는 세가지의 directives들이 있다.

	1. 컴포넌트 - 템플릿을 포함한 directive
 	2. 구조적 directives - DOM elements를 더하거나 제거하여 DOM 레이아웃을 바꾸는 directive
 	3. 속성 directives - 요소, 컴포넌트 혹은 다른 directive의 외형이나 동작을 변형시키는 directive

## Angular의 life cycle

- angular는 생명주기 앞에 ng라는 고유한 글자가 붙는 hook 메소드를 갖는데, 이 생명주기의 순서는 다음의 순서를 따른다.

  Constructor

  ngOnChanges

  ngOnInit

  ngDoCheck

  ​	ngAfterContentInit

  ​	ngAfterContentChecked

  ​	ngAfterViewInit

  ​	ngAfterViewChecked

  ngOnDestory

Angular directive 역시 컴포넌트와 같은 ng가 붙는 hook 메소드를 사용한다. 모든 생명주기를 구현할 필요는 없지만 필요한 시점에 맞추어 메소드를 사용하면 된다.

