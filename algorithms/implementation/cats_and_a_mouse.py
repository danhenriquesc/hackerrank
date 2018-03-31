#!/bin/python3

import os


def catAndMouse(x, y, z):
    dA = abs(z - x)
    dB = abs(z - y)

    if dA == dB:
        return "Mouse C"

    return "Cat {}".format("A" if dA < dB else "B")


if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        x, y, z = map(int, input().split())

        result = catAndMouse(x, y, z)

        f.write(result + '\n')

    f.close()
