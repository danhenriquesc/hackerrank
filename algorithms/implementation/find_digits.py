#!/bin/python3


def findDigits(n):
    count = 0
    for c in str(n):
        if c != "0":
            count += not (n % int(c))
    return count


if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        result = findDigits(n)
        print(result)
