def combination(n):
    return (n * (n - 1)) / 2


def find_set(a):
    k = 0
    for it in l:
        if(a in it):
            return k
        k += 1


(n, i) = (int(i) for i in input().strip().split())
l = [set([i]) for i in range(n)]

for j in range(i):
    f = 0
    (a, b) = (int(i) for i in input().strip().split())
    a = find_set(a)
    b = find_set(b)
    if(a != b):
        l[a] = l[a].union(l[b])
        l.pop(b)

m = combination(n)
for it in l:
    m -= combination(len(it))

print(int(m))
