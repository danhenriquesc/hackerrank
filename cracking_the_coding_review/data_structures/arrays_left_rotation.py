_, k = list(map(int, input().strip().split(' ')))
a = list(input().strip().split(' '))

result = a[k:] + a[:k]
print(' '.join(result))
