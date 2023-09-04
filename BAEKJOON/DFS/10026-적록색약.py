import sys
sys.setrecursionlimit(10**6)

num = int(input())

map = []
for i in range(num):
    map.append(list(input()))

len = len(map[0])
d = [[0] * len for _ in range(num)]
colors = ['R', 'G', 'B']

def dfs(x, y, color):
    if x < 0 or y < 0 or x >= num or y >= len:
        return False
    if d[x][y] == 0 and map[x][y] == colors[color]:
        d[x][y] = 1
        dfs(x - 1, y, color)
        dfs(x + 1, y, color)
        dfs(x, y - 1, color)
        dfs(x, y + 1, color)
        return True
    return False

result = 0
for i in range(num):
    for j in range(len):
        if dfs(i,j,0) == True:
            result+=1
        if dfs(i,j,1) == True:
            result+=1
        if dfs(i,j,2) == True:
            result+=1
print(result, end = ' ')


result = 0
d = [[0] * len for _ in range(num)]
for i in range(num):
    for j in range(len):
        if map[i][j] == 'G':
            map[i][j] = 'R'
for i in range(num):
    for j in range(len):
        if dfs(i,j,0) == True:
            result+=1
        if dfs(i,j,2) == True:
            result+=1
print(result)