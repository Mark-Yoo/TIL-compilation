const fruits = [
  { id: 1, name: "apple", price: 1000 },
  { id: 2, name: "orange", price: 5000 },
  { id: 3, name: "pear", price: 10000 },
  { id: 4, name: "grape", price: 3000 },
  { id: 5, name: "melon", price: 20000 },
];

// 고차함수 map 구현해보기
const map = (fn, items) => {
  let result = [];

  for (const item of items) {
    result.push(fn(item));
  }
  return result;
};

console.log(map((item) => item.name, fruits));
console.log(map((item) => item.price, fruits));
