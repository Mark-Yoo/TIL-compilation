// 1번 예제
function* getOddNumInf(num = 0) {
  while (true) {
    num++;
    if (!(num % 2)) {
      yield num;
    }
  }
}

let iter = getOddNumInf();

console.log(iter);
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());

// 2번 예제
function* infinity(num = 0) {
  while (true) yield num++;
}

function* limitation(num, iter) {
  for (const i of iter) {
    yield i;
    if (i === num) return;
  }
}

function* oddNum(num) {
  for (const i of infinity(1)) {
    if (i % 2) yield i;
    if (i === num) return;
  }
}

let iter2 = limitation(4, [1, 2, 3, 4, 5, 6]);

console.log(iter2);
console.log(iter2.next());
console.log(iter2.next());
console.log(iter2.next());
console.log(iter2.next());
console.log(iter2.next());

// 3번 예제

console.log([...oddNum(10)]);
const [first, ...rest] = oddNum(20);
console.log("first", first, "rest", rest);
