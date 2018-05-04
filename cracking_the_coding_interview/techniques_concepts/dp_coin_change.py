#Dynamic Programming
n, m = input().strip().split(' ')
n, m = [int(n), int(m)]
coins = [int(coins_temp) for coins_temp in input().strip().split(' ')]
coins = [0] + coins

T = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]

for p in range(1, m + 1):
    T[p][0] = 1
    for i in range(1, n + 1):
        tot = 0
        for k in range(1, p + 1):
            if i - coins[k] >= 0:
                tot += T[k][i - coins[k]]
        T[p][i] = tot

print(T[m][n])


# Recursive with memoization
n, m = input().strip().split(' ')
n, m = [int(n), int(m)]
coins = [int(coins_temp) for coins_temp in input().strip().split(' ')]
coins = [0] + sorted(coins)

memo = [[-1 for _ in range(275)] for _ in range(55)]


def charge(m, n):
    if n < 0 or m == 0:
        return 0
    elif n == 0:
        return 1
    else:
        tot = 0
        i = 1
        while i <= m:
            t = n - coins[i]
            if memo[i][t] == -1:
                memo[i][t] = charge(i, t)

            tot += memo[i][t]
            i += 1
        return tot


print(charge(m, n))
