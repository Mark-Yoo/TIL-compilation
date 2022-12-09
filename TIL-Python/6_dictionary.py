# Python의 Dictionary 문법은 Javascript와 비슷
# 키와 값으로 이루어져 있다.
sample = { 'bring' : '가져오다', 'kind' : '친절하다', 'example' : '예제' }
print(sample)
print(sample['bring'])

menu = { '김밥' : 3000, '라면' : 2500, '쫄면' : 4000, '떡만둣국' : 5000 }
menu['김밥'] = 3500
print(menu['김밥'])
del menu['떡만둣국']
print(menu)
print(menu.keys())
print(menu.values())
print(menu.items())