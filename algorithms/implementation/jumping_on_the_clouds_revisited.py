#!/bin/python3


def jumpingOnClouds(n, c, k):
    current = 0
    E = 100

    while (True):
        E -= 1
        current = (current + k) % n
        if (c[current] == 1):
            E -= 2

        if not current:
            break

    return E


if __name__ == "__main__":
    n, k = input().strip().split(' ')
    n, k = [int(n), int(k)]
    c = list(map(int, input().strip().split(' ')))
    result = jumpingOnClouds(n, c, k)
    print(result)
