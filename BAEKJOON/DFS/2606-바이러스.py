num = int(input())
connect = int(input())

graph = [[] for _ in range(num + 1)]
for i in range(connect):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [0] * (num + 1)

def dfs(v):
    visited[v] = 1
    for i in graph[v]:
        if visited[i] == 0:
            dfs(i)

dfs(1)
print(sum(visited) - 1)