# Core Concepts

---

## Overview

Recoil은 atoms(공유된 상태)에서부터 Selector(순수 함수)까지의 흐르는 데이터 플로우 그래프를 만들게 해주고 이를 당신의 리액트 컴포넌트들로 흐르도록 해줍니다.

Atoms는 컴포넌트들이 볼 수 있는 '상태의 구성단위'입니다. Selector들은 이 상태를 동기적으로든, 비동기적으로든 바꿀 수 있습니다.

---

## Atoms

Atoms는 상태의 구성단위입니다. Atoms는 업데이트가 가능하고 구독 가능합니다: atom이 업데이트 되었을 때에는 각각의 구독중인 컴포넌트들이 새로운 값으로 리렌더링 됩니다. atom은 런타임에도 생성될 수 있습니다. Atoms는 리액트의 로컬 컴포넌트 상태의 자리에도 사용될 수 있습니다. 만약 똑같은 atom이 여러 컴포넌트들에서 사용중이라면 그 모든 컴포넌트들이 상태를 공유합니다.

Atoms는 atom 함수를 사용하여 만들 수 있습니다.

```react
const fontSizeState = atom({
	key: 'fontSizeState',
	default: 14,
});
```

Atoms는 디버깅, 영속성, 그리고 모든 atoms의 지도를 볼 수 있게 해주는 일부의 선진 API에 사용되는 고유한 키를 필요로 합니다. 두 atom이 같은 키를 갖는 것은 잘못된 것이므로 이 키들은 전역에서도 고유해야만 합니다. 리액트 컴포넌트의 상태처럼 atoms도 기본값을 가집니다.

컴포넌트에서 atom을 읽고 쓰기 위해서는 `useRecoilState` 라는 hook을 사용합니다. 이는 리액트의 `useState`와 같지만, 컴포넌트 사이에서 상태를 공유할 수 있습니다.

```React
function FontButtom() {
	const [fontSize, setFontSize] = useRecoilState(fontSizeState);
	return (
  	<button onClick={() => setFontSize((size) => size + 1)} style={{fontSize}}>
			Click to Enlarge
    </button>
  );
}
```

버튼을 클릭하는 것은 버튼의 글씨 크기를 하나씩 증가시킵니다. 하지만 이제 다른 컴포넌트들도 같은 폰트 사이즈를 사용할 수 있습니다.

```react
function Text() {
  const [fontSize, setFontSize] = useRecoilState(fontSizeState);
  return <p style={{fontSize}}>This text will incereate in size too</p>;
}
```

## Selectors

---

Selector는 atoms나 다른 Selector들을 인풋으로 받는 순수 함수입니다. 이러한 상류 atoms 혹은 Selector들이 업데이트 되면, Selector 함수는 재평가 됩니다. 컴포넌트들은 선택자를 atoms과 같이 구독할 수 있고, Selector들이 바뀌면 리렌더링 될 겁니다.

선택자들은 상태에 기반한 파생 데이터를 계산하기 위해 사용됩니다. 이러한 기능은 최소한의 상태들이 atoms에 저장되어 있으므로 불필요한 상태들을 가지는 것을 피할수 있게 해줍니다.

컴포넌트의 관점에서 선택자와 atoms는 같은 인터페이스를 가지면서 서로의 대체제가 되는 것도 가능합니다.

선택자는 selector 함수를 사용하여 정의합니다.

```react
const fontSizeLabelState = selector({
  key: 'fontSizeLabelState',
  get: ({get}) => {
    const fontSize = get(fontSizeState);
    const unit = 'px';
    
    return `${fontSize}${unit}`;
  },
});
```

`get` 프로퍼티가 입력될 함수이며 이는 atoms의 값과 다른 선택자에 전달된 `get` 인자를 사용하여 접근 할 수 있습니다. 다른 atom이나 선택자에 접근할 때마다, 다른 atom이나 선택자를 업데이트 하는 것이 이것을 다시 계산하게 만드는 의존성 관계가 형성됩니다.

이 `fontSizeLabelState` 예시를 보면, 선택자는 하나의 의존성을 갖습니다: `fontSizeState` atom이다. 개념적으로 `fontSizeLabelState` 선택자는 `fontSizeState`를 입력으로 받고 정형화된 font size 라벨을 출력하는 순수함수처럼 동작합니다.

Selector는 atom이나 선택자를 인자로 받고 이에 상응하는 값을 리턴하는 `useRecoilValue()`를 사용해서 읽을 수 있습니다. `useRecoilState()`는 `fontSizeLabelState` Selector가 writable 속성이 아니어서 사용하지 않습니다. (writable Selector에 대하여 정보를 더 원하신다면 [API reference](https://recoiljs.org/docs/api-reference/core/selector) 를 확인해주세요.)

``````react
function FontButton() {
  const [fontSize, setFontSize] = useRecoilState(fontSizeState);
  const fontSizeBLabel = useRecoilValue(fontSizeLabelState);
  
  return (
  	<>
    	<div>Current font size: {fontSizeLabel}</div>
    
   		<button onClick={() => setFontSize(fontSize + 1)} style= {{fontSize}}>
    		Click to Enlarge
    	</button>
    <>
  );
}
``````

이제 버튼을 누르면 두 가지 기능을 합니다: 폰트의 사이즈를 키우면서 현재 폰트 사이즈를 반영하기 위해서 font size label을 업데이트 합니다.

