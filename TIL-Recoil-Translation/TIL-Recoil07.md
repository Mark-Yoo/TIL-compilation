# Selectors

---

Selector는 파생된 상태들을 대표합니다. 파생된 데이터를 주어진 상태를 어떠한 방식으로 변형시키는 순수 함수에 전달된 상태의 아웃풋이라고 생각할 수 있습니다.

파생된 상태는 다른 데이터에 의존하는 다이나믹한 데이터를 빌드하게 해주는 강력한 컨셉입니다. '할 일 리스트' 어플리케이션의 context에서 다음과 같은 것들을 파생 데이터라고 간주하겠습니다:

- 필터링 된 '할 일 리스트': 일부 기준에 따라 필터링 된 특정 항목이 있는 새 리스트를 생성하여 전체 '할 일 리스트'에서 파생됩니다. (예를 들어 이미 완료된 아이템들을 필터링하는 일)

- '할 일 리스트' 통계: 리스트의 총 아이템의 갯수, 완료된 아이템의 갯수, 그리고 완료된 아이템의 퍼센티지와 같은 리스트의 유용한 어트리뷰트를 계산하여 전체 '할 일 리스트'에서 파생됩니다.

필터링된 '할 일 리스트'를 구현하기 위해서는 atom에 값이 저장될 수 있는 필터의 기준들을 정해줄 필요가 있습니다. 사용할 필터 옵션들은: "Show All", "Show Completed", 그리고 "Show Uncompleted" 입니다. 기본값은 "Show All"입니다:

```react
const todoListFilterState = atom({
  key: 'todoListFilterState',
  default: 'Show All',
});
```

`todoListFilterState`와 `todoListState`를 사용하여 필터링된 리스트를 파생하는 `filteredTodoListState` selector를 빌드 할 수 있습니다.

```react
const filteredTodoListState = selector({
  key: 'filteredTodoListState',
  get: ({get}) => {
    const filter = get(todoListFilterState);
    const list = get(todoListState);

    switch (filter) {
      case 'Show Completed':
        return list.filter((item) => item.isComplete);
      case 'Show Uncompleted':
        return list.filter((item) => !item.isComplete);
      default:
        return list;
    }
  },
});
```

`filteredTodoListState`는 내부적으로 두 개의 의존성을 따릅니다. `todoListFilterState`와 `todoListState` 중 변경점이 생길 경우 재실행됩니다.

> 컴포넌트의 시점에서, selectors는 atom을 읽는데에 사용하는 것과 같은 hook을 사용하여 읽을 수 있습니다. 그러나 특정한 hooks들은 **writable 상태** 일 때에만 동작한다는 것을 알아두어야 합니다.(예: **`useRecoilState()`**). 모든 atoms는 writable 상태지만 몇 가지 selectors들만 writable 상태로 간주됩니다. (**`get`** 과 **`set`** 프로퍼티를 둘 다 가지고 있는 selector). 좀 더 많은 정보를 원하신다면 [Core Concepts](https://recoiljs.org/docs/introduction/core-concepts) 페이지를 참고해주세요.

필터링된 '할 일 리스트'를 `TodoList` 컴포넌트에서 한 줄 바꾸는 것만큼 간단합니다:

```react
function TodoList() {
  // changed from todoListState to filteredTodoListState
  const todoList = useRecoilValue(filteredTodoListState);

  return (
    <>
      <TodoListStats />
      <TodoListFilters />
      <TodoItemCreator />

      {todoList.map((todoItem) => (
        <TodoItem item={todoItem} key={todoItem.id} />
      ))}
    </>
  );
}
```

`todoListFilterState`는 "Show All"을 기본값으로 가지고 있어 UI가 모든 '할 일'을 보여주고 있습니다. 필터를 바꾸기 위해서 `TodoListFilters` 컴포넌트를 구현해야 합니다:

```react
function TodoListFilters() {
  const [filter, setFilter] = useRecoilState(todoListFilterState);

  const updateFilter = ({target: {value}}) => {
    setFilter(value);
  };

  return (
    <>
      Filter:
      <select value={filter} onChange={updateFilter}>
        <option value="Show All">All</option>
        <option value="Show Completed">Completed</option>
        <option value="Show Uncompleted">Uncompleted</option>
      </select>
    </>
  );
}
```

몇 줄의 코드만으로 필터링을 구현할 수 있었습니다! `TodoListStats` 컴포넌트를 구현하기 위해서 같은 컨셉을 사용하겠습니다.

다음과 같은 수치들을 표시하려고 합니다:

- 할 일 아이템의 총 갯수
- 완료한 아이템의 총 갯수
- 완료되지 않은 아이템의 총 갯수
- 완료된 아이템의 퍼센티지

