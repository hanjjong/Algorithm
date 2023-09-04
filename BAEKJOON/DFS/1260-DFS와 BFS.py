from collections import deque
num, line, start = map(int, input().split())

graph = [[] for _ in range(num + 1)]
for i in range(line):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

for i in graph:
    i.sort()


def dfs(v):
    visited[v] = 1
    print(v, end = ' ')
    for i in graph[v]:
        if visited[i] == 0 :
            dfs(i)

def bfs(v):
    queue = deque()
    queue.append(v)
    visited[v] = 1
    while queue:
        v = queue.popleft()
        print(v, end = ' ')
        for i in graph[v]:
            if visited[i] == 0:
                visited[i] = 1
                queue.append(i)

visited =  [0] * (num + 1)
dfs(start)
print()
visited =  [0] * (num + 1)
bfs(start)