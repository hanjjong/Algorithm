import sys
sys.setrecursionlimit(10**6)

num = int(input())

array = []
for i in range(num):
    array.append(list(map(int,input())))

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

town = []
apt = 0
def dfs(x, y):
    global count
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx <num and 0 <= ny <num and array[nx][ny] == 1:
            array[nx][ny] = 0
            count += 1
            dfs(nx, ny)
        

for i in range(num):
    for j in range(num):
        if array[i][j] == 1:
            array[i][j] = 0
            count = 1
            dfs(i,j)
            apt += 1
            town.append(count)

town.sort()
print(apt)
print(*town,sep = '\n')
