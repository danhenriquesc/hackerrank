#!/bin/python3


def camelcase(s):
    return len(list(filter(lambda x: x, map(lambda x: x != x.lower(), s)))) + 1


if __name__ == "__main__":
    s = input().strip()
    result = camelcase(s)
    print(result)
