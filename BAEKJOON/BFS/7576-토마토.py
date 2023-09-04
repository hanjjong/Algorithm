from collections import deque
import sys

row, col = map(int,input().split())

graph = []
for i in range(col):
    graph.append(list(map(int, input().split())))

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

queue = deque()

for i in range(col):
    for j in range(row):
        if graph[i][j] == 1:
            queue.append((i, j))

while queue:
    x, y = queue.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx>= col or ny >= row:
            continue
        if graph[nx][ny] == -1:
            continue
        if graph[nx][ny] == 0:
            graph[nx][ny] = graph[x][y] + 1
            queue.append((nx, ny))
flag = 0
day = 0
for i in graph:
    for j in i:
        if j == 0 and flag == 0:
            print(-1)
            flag = 1
    day = max(day, max(i))
if flag == 0:
    print(day - 1)
