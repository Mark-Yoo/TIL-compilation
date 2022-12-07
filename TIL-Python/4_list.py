abc = [1, 2, 3, 4, 5]
print(type(abc), abc)

spending_year = [1, 13, 30, 24, 52, 68, 80, 99, 10, 13, 25, 77]
spending_year[0] += 10
print(type(spending_year), spending_year)

for s in spending_year:
    print(s)

print('use range')
for i in range(6):
    print(spending_year[i])

print('use len keyword')
for j in range(len(spending_year)):
    print(j)

print('-1st item from spending_year list')
print(spending_year[-1])

print('-3rd item from spending_year list')
print(spending_year[-3])

food = ['피자', '스테이크', '치킨', '된장찌개', '김치찌개']
search = input('찾고 계신 음식을 입력해주세요')

if search in food:
    print(food.index(search) + 1, '위입니다.')
else:
    print(search, '은/는 순위에 없습니다.')