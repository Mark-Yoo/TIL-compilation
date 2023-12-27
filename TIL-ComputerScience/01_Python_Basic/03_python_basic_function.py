#  *(asterisk)가 하나일 경우 인수가 tuple 형태로 변환되어 전달됨
def function(*x):
    test_tuple = []
    for i in x:
        y = i * 3
        test_tuple.append(y)
    return test_tuple


# **(asterisk)가 두 개일 경우, dictionary 형태로 변환되어 전달됨
def test_func(**x):
    return x


# 전역에 선언된 변수를 명시적으로 사용하기 위한 global 키워드
a = 3


def global_test_func(x):
    global a
    y = a + x
    return y


result = function(4, 5, 6)
result2 = test_func(a=5, b=3, c=6)
result3 = global_test_func(10)
print(result)
print(result2)
print(result3)
