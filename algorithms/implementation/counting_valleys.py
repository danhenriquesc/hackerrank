#!/bin/python3


def countingValleys(n, s):
    level = 0
    old_level = 0
    valleys = 0
    for step in s:
        old_level = level
        if step == 'D':
            level -= 1
        else:
            level += 1

        if level >= 0:
            if old_level < 0:
                valleys += 1

    return valleys


if __name__ == "__main__":
    n = int(input().strip())
    s = input().strip()
    result = countingValleys(n, s)
    print(result)
