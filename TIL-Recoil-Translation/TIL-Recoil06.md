# Atoms

---

Atom은 어플리케이션 상태의 진실의 근원을 가지고 있습니다. 이 '할 일 리스트'에서 진실의 근원은 각 객체가 할 일 아이템을 대변하는 객체들의 배열이 될 것입니다.

이 리스트를 `atom()` 함수를 사용해 만들고, atom `todoListState` 라고 부르겠습니다.

```react
const todoListState = atom({
  key: 'todoListState',
  default: [],
});
```

atom에 고유한 키를 주고 디폴트 값을 빈 배열로 설정하겠습니다. 이 atom의 내용물을 읽기 위해서 Todolist 컴포넌트에서  `useRecoilValue()` hook을 사용 할 수 있습니다.

```react
function TodoList() {
  const todoList = useRecoilValue(todoListState);

  return (
    <>
      {/* <TodoListStats /> */}
      {/* <TodoListFilters /> */}
      <TodoItemCreator />

      {todoList.map((todoItem) => (
        <TodoItem key={todoItem.id} item={todoItem} />
      ))}
    </>
  );
}
```

주석처리된 컴포넌트들은 다음에 오는 섹션들로 대체될 것입니다.

새로운 '할 일 아이템'을 만들기 위해서 `todoListState` 의 컨텐츠를 업데이트 할 setter함수에 접근 할 필요가 있습니다. `useSetRecoilState()` hook을 사용하여 `TodoItemCreator` 컴포넌트에서 setter 함수를 가져올 수 있습니다.

````react
function TodoItemCreator() {
  const [inputValue, setInputValue] = useState('');
  const setTodoList = useSetRecoilState(todoListState);

  const addItem = () => {
    setTodoList((oldTodoList) => [
      ...oldTodoList,
      {
        id: getId(),
        text: inputValue,
        isComplete: false,
      },
    ]);
    setInputValue('');
  };

  const onChange = ({target: {value}}) => {
    setInputValue(value);
  };

  return (
    <div>
      <input type="text" value={inputValue} onChange={onChange} />
      <button onClick={addItem}>Add</button>
    </div>
  );
}

// 고유한 Id를 생성하기 위한 유틸리티
let id = 0;
function getId() {
  return id++;
}
````

이전의 '할 일 리스트'를 기반으로 새로운 '할 일 리스트'를 만들 수 있도록 Setter 함수의 Updater form을 사용합니다.

`TodoItem` 컴포넌트는 텍스트를 수정하거나 삭제하는 일이 가능하며 '할 일 아이템'의 값을 표시해줄겁니다.  `todoListState` 를 읽기위해서, 또한 '할 일 텍스트 업데이트' 및  '할 일 완료하기', '할 일 삭제하기' 기능을 위해 사용되는 setter 함수를 가져오기 위해서 `useRecoilState()` 를 사용합니다.

````react
function TodoItem({item}) {
  const [todoList, setTodoList] = useRecoilState(todoListState);
  const index = todoList.findIndex((listItem) => listItem === item);

  const editItemText = ({target: {value}}) => {
    const newList = replaceItemAtIndex(todoList, index, {
      ...item,
      text: value,
    });

    setTodoList(newList);
  };

  const toggleItemCompletion = () => {
    const newList = replaceItemAtIndex(todoList, index, {
      ...item,
      isComplete: !item.isComplete,
    });

    setTodoList(newList);
  };

  const deleteItem = () => {
    const newList = removeItemAtIndex(todoList, index);

    setTodoList(newList);
  };

  return (
    <div>
      <input type="text" value={item.text} onChange={editItemText} />
      <input
        type="checkbox"
        checked={item.isComplete}
        onChange={toggleItemCompletion}
      />
      <button onClick={deleteItem}>X</button>
    </div>
  );
}

function replaceItemAtIndex(arr, index, newValue) {
  return [...arr.slice(0, index), newValue, ...arr.slice(index + 1)];
}

function removeItemAtIndex(arr, index) {
  return [...arr.slice(0, index), ...arr.slice(index + 1)];
}
````

이제 완전하게 작동하는 '할 일 리스트'가 완성되었습니다! 다음 섹션에서는 selector를 사용하여 이 리스트를 다음 단계로 올릴 수 있는지 알아보도록 하겠습니다.