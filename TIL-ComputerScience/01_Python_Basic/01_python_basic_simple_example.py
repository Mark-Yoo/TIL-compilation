for i in range(1, 10):
    for j in range(1, 10):
        print('{} x {} = {}'.format(i, j, i * j), end='\t')
    print('\n')


# Tuple
for m in (1, 2, 3):
    print('m : {}'.format(m), end='\t')
print('\n')

# String
lines = 'hello'
for s in lines:
    print('s : {}'.format(s), end='\t')
print('\n')

# List
li = [1, 2, 3]
for n in li:
    print('n : {}'.format(n), end='\t')
print('\n')

# Get multiples of 4
for l in range(1, 7):
    for o in range(1, 7):
        k = l + o
        if k % 4 == 0:
            print('{} + {} = {}'.format(l, o, l + o))