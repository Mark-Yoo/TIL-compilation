import os
from multiprocessing import Process


def f(x):
    print(os.getpid())
    print(x*x)


print(__name__)

if __name__ == "__main__":
    numbers = [1, 2, 3, 4]
    proc1 = Process(target=f, args=(numbers[0],))
    proc1.start()
    proc2 = Process(target=f, args=(numbers[1],))
    proc2.start()
    proc3 = Process(target=f, args=(numbers[2],))
    proc3.start()
    proc4 = Process(target=f, args=(numbers[3],))
    proc4.start()
    proc1.join()
    proc2.join()
    proc3.join()
    proc4.join()