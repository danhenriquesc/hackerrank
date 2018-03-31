#!/bin/python3


def hackerrankInString(s):
    find = "hackerrank"
    i = 0

    for c in s:
        if find[i] == c:
            i += 1
            if i >= len(find):
                return("YES")

    return("NO")


if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        s = input().strip()
        result = hackerrankInString(s)
        print(result)
