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
