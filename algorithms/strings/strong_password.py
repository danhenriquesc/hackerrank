#!/bin/python3


def minimumNumber(n, password):
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"

    digit = 1
    lower = 1
    upper = 1
    special = 1

    for c in password:
        if c in numbers:
            digit = 0
        if c in lower_case:
            lower = 0
        if c in upper_case:
            upper = 0
        if c in special_characters:
            special = 0

    missing = digit + lower + upper + special

    return max(missing, 6 - len(password))


if __name__ == "__main__":
    n = int(input().strip())
    password = input().strip()
    answer = minimumNumber(n, password)
    print(answer)
