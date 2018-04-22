n = int(input().strip())
a = list(map(int, input().strip().split(' ')))

swaps = 0
for i in range(n):
    for j in range(n - 1):
        if(a[j] > a[j + 1]):
            a[j], a[j + 1] = a[j + 1], a[j]
            swaps += 1

print('Array is sorted in {} swaps.'.format(swaps))
print('First Element: {}'.format(a.pop(0)))
print('Last Element: {}'.format(a.pop()))
