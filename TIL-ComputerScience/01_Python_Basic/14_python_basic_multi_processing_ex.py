import time
import os
from multiprocessing import Pool


def func(x):
    return x[0] * x[1]


if __name__ == "__main__":
    start = int(time.time())
    num_pool = 2
    pool = Pool(num_pool)
    # print(pool.map(func, [[1, 2],[3, 4]]))
    print(pool.map(func, zip(range(100), range(100))))
    pool.close()
    print("*** run time(sec) :", int(time.time()) - start)