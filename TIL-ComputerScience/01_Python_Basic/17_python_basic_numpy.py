import numpy as np

data = np.array([1, 2, 3, 4], dtype=np.float64)
print(data)

print(np.array([[1, 2, 3, 4], [2, 2, 3, 4]]).shape)

print(np.eye(5))

# how numpy empty works
a = np.empty((3, 5))
print(a)

a[0] = 1
print(a)

a[2] = 3
print(a.shape)

for i in range(15):
    a[i // 5][i % 5] = i

print(a)
print(a[[1, 2], [0, 3]])