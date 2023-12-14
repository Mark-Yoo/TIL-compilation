# set doesn't allow duplicates and order doesn't matter
# Cannot be indexed or sliced due to its lack of order

a = {1, 2, 3}
b = {1, 2, 3}
c = set('hi')
d = set('hello')

# a.add(5)
# b.clear()
# c.union(b)
print(d.intersection(c))
print(c.difference(b))


print(a)
print(b)
print(c)
print(d)
