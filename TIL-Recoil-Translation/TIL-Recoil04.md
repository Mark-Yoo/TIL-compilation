# Getting Started

---

## Create React App

Recoil은 React를 위한 상태 관리 라이브러리입니다. 그러므로 Recoil을 실행하기 위해서는 React가 설치되어 있어야 합니다. React 어플리케이션을 사용하는 가장 쉽고 추천하는 방법은 [Create React App](https://github.com/facebook/create-react-app#creating-an-app):

````shell
npx create-react-app my-app
````

> [npx](https://medium.com/@maybekatz/introducing-npx-an-npm-package-runner-55f7d4bd282b) 는 npm 5.2+ 혹은 그 이상의 버전과 함계 제공되는 패키지 실행툴입니다, [이전 버전의 npm을 위한 안내서](https://gist.github.com/gaearon/4064d3c23a77c74a3614c498a8bb1c5f)를 확인해주세요.

Create React App을 설치하기 위한 방법들을 더 확인하시려면 [공식 문서](https://github.com/facebook/create-react-app#creating-an-app)를 참조하세요.

## Installation

Recoil 패키지는 npm 생태계를 따라갑니다. 최신의 안정적인 버전을 설치하기 위해서는, 다음 명령을 입력하면 됩니다.

```shell
npm install recoil
```

yarn을 사용하신다면:

```shell
yarn add recoil
```

## RecoilRoot

Recoil을 사용하는 컴포넌트는 부모 트리의 어딘가에는 `RecoilRoot`가 있어야 합니다. `RecoilRoot`가 들어가기 좋은 자리는 루트 컴포넌트입니다.

````react
import React from 'react';
import {
  RecoilRoot,
  atom,
  selector,
  useRecoilState,
  useRecoilValue,
} from 'recoil';

function App() {
  return (
    <RecoilRoot>
      <CharacterCounter />
    </RecoilRoot>
  );
}
````

다음 섹션에서 `CharacterCounter` 컴포넌트를 대체하겠습니다.

## Atom

Atom은 **상태의 조각**을 대표합니다. Atoms는 어떤 컴포넌트에서든 읽고 쓸 수 있습니다. Atom의 값을 읽을 수 있는 컴포넌트는 내재적으로 그 atom을 구독하고 있습니다. 그러므로 atom에서 어떠한 업데이트가 발생하게 되면 atom을 구독하고 있는 컴포넌트에 리렌더링을 발생시킵니다.

```react
const textState = atom({
  key: 'textState', // unique ID (with respect to other atoms/selectors)
  default: '', // default value (aka initial value)
});
```

atom에 읽고 쓰기 위한 컴포넌트는 다음과 같이 `useRecoilState()`를 사용하여야 합니다:

```react
function CharacterCounter() {
  return (
    <div>
      <TextInput />
      <CharacterCount />
    </div>
  );
}

function TextInput() {
  const [text, setText] = useRecoilState(textState);

  const onChange = (event) => {
    setText(event.target.value);
  };

  return (
    <div>
      <input type="text" value={text} onChange={onChange} />
      <br />
      Echo: {text}
    </div>
  );
}
```

## Selector

Selector는 **파생된 데이터**를 대표합니다. 파생된 데이터는 상태의 변환입니다. 파생된 데이터는 주어진 상태를 어떤식으로든 수정하는, 순수 함수에 전달된 상태의 아웃풋이라고 생각 할 수도 있습니다:

```react
const charCountState = selector({
  key: 'charCountState', // unique ID (with respect to other atoms/selectors)
  get: ({get}) => {
    const text = get(textState);

    return text.length;
  },
});
```

`useRecoilValue()` hook을 사용하여 `charCountState`의 값을 읽을 수 있습니다:

```react
function CharacterCount() {
  const count = useRecoilValue(charCountState);

  return <>Character Count: {count}</>;
}
```

## Demo

다음은 완성된 프로덕트입니다:

