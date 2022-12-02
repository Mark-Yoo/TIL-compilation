import random
print('Gugudan!')
answer, a, b = 0, 0, 0
while answer == a * b:
    a, b = random.randint(2, 9), random.randint(1, 9)
    answer = input(str(a) + 'x' + str(b) + '? ')
    answer = int(answer)
print ('Wrong! the answer is', a * b)