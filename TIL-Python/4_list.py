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