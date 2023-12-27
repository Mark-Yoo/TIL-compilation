# generator / yield
# yield를 통해서 생성되는 값들은 호출 시점에서 계산된다 (lazy operator)
def gen(n):
    while n > 0:
        yield n
        n = n - 1


print(gen(10))
print(list(gen(10)))