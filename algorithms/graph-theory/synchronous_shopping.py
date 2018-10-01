from heapq import heappush, heappop


def lstin():
    return list(map(int, input().strip().split()))


def shopping(edges, shop, N):
    visited = [None] + [[False] * 1024 for _ in range(N)]
    pq = [(0, 1, shop[1])]
    while pq:
        uc, u, uf = heappop(pq)
        if u == N:
            yield uc, uf
        if not visited[u][uf]:
            visited[u][uf] = True
            for v, vc in edges[u]:
                vf = uf | shop[v]
                if not visited[v][vf]:
                    heappush(pq, (uc + vc, v, vf))


N, E, K = lstin()
full = (1 << K) - 1
shop = [0] * (N + 1)
for i in range(1, N + 1):
    for k in lstin()[1:]:
        shop[i] |= 1 << (k - 1)
edges = [None] + [list() for _ in range(N)]
for _ in range(E):
    u, v, c = lstin()
    edges[u].append((v, c))
    edges[v].append((u, c))

bset = set()
bought = [False] * 1024
bought[0] = True
bset.add(0)
for cost, fishes in shopping(edges, shop, N):
    if not bought[fishes]:
        for already_bought in bset:
            if already_bought | fishes == full:
                print(cost)
                exit()
        bought[fishes] = True
        bset.add(fishes)
