#!/bin/python3


def extraLongFactorials(n):
    if (n == 1):
        return 1
    else:
        return n * extraLongFactorials(n - 1)


if __name__ == "__main__":
    n = int(input().strip())
    print(extraLongFactorials(n))
