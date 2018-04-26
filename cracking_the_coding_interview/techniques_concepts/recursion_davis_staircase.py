memo = {1: 1, 2: 2, 3: 4}


def climb(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    else:
        c = 0

        for i in [1, 2, 3]:
            t = memo.get(n - i)
            if not t:
                memo[n - 1] = climb(n - 1)

            c += memo.get(n - i)

        return c


s = int(input().strip())
for a0 in range(s):
    n = int(input().strip())

    print(climb(n))
