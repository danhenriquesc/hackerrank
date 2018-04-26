from math import sqrt, floor


def is_prime(n):
    if n <= 1:
        return False
    elif n == 2:
        return True
    elif not n % 2 or not n % 3:
        return False
    else:
        r = True

        for i in range(5, floor(sqrt(n)) + 1, 2):
            if not n % i:
                r = False

        return r


p = int(input().strip())
for a0 in range(p):
    n = int(input().strip())

    print('{}'.format('Prime' if is_prime(n) else 'Not prime'))
