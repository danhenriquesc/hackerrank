def dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(graph[vertex] - visited)
    return visited


def make_graph_alias(i, j):
    return '{}_{}'.format(i, j)


def getBiggestRegion(grid):
    graph = {}

    for i, line in enumerate(grid):
        for j, value in enumerate(line):
            if value:
                connections = []

                for k in [-1, 0, 1]:
                    for l in [-1, 0, 1]:
                        try:
                            if (k != 0 or l != 0) and (i + k) >=0 and (j + l) >=0 and grid[i + k][j + l]:
                                connections.append(make_graph_alias(i + k, j + l))
                        except:
                            pass

                graph.update({make_graph_alias(i, j): set(connections)})

    longest = -1
    for i, line in enumerate(grid):
        for j, value in enumerate(line):
            if value:
                longest = max(longest, len(dfs(graph, make_graph_alias(i, j))))
    return longest


n = int(input().strip())
m = int(input().strip())
grid = []
for grid_i in range(n):
    grid_t = list(map(int, input().strip().split(' ')))
    grid.append(grid_t)

print(getBiggestRegion(grid))
