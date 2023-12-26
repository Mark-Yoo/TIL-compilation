# use while statment to find smallest multiple of 4
i = 0
while True:
    if i % 4 == 0:
        print('i : {}'.format((i)))
    if i == 100:
        print('End of repeatation')
        break
    i += 1