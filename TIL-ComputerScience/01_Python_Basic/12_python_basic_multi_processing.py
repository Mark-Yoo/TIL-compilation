import os
from multiprocessing import Pool


def f(x):
    print(x, os.getpid())
    return x*x


if __name__ == "__main__":
    p = Pool(4)
    result = p.map(f, range(100000))
    p.close()
    print(sum(result))