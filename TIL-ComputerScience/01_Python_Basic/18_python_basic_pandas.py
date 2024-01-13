import pandas as pd

a = pd.DataFrame([[1, 2, 3, 4], [5, 6, 7, 8]], columns=['col', 'col2', 'col3', 'col4'])
print(a)

b = pd.DataFrame({'col1': [1, 2, 3, 4], 'col2': [5, 6, 7, 8]})
print(b)

print(a['col'])
print(a[['col', 'col3']])
print(a[1:])
print(a.apply(sum))
print(a.apply(sum, axis=1))
print(a.apply(lambda x: x[0]*x[1], axis=0))
# 'applymap' is now depreciated (since 2.1.0)
# print(a.applymap(lambda x: x ** 3))
# use 'map' instead of 'applymap'
print(a.map(lambda x: x ** 3))

c = pd.DataFrame([['장미반', 30], ['기린반', 26], ['병아리반', 32], ['사슴반', 20]], columns=['반', '인원'])
print(c)
print(c.groupby('반').aggregate(lambda x: sum(x)))
print(c.groupby('반').agg(lambda x: sum(x)))
