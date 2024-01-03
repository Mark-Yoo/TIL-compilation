def test(count):
    if count > 0:
        count -= 1
        print(count, '현재')
        test(count)
    else:
        return 0


def test1(arr):
    for i in enumerate(arr):
        print(i)


def test2(func, x):
    for i in x:
        func(i)
        print(i)


test(10)
test1([1, 2, 3, 4])
test2(lambda x: x + 1, (1, 2, 3, 4))