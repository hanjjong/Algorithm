import sys

n, m = map(int, sys.stdin.readline().split())
arr = [ list(map(int,sys.stdin.readline().split())) for _ in range(n)]

T = int(sys.stdin.readline())
pos = [ list(map(int, sys.stdin.readline().split())) for _ in range(T)]


s = [ [0 for _ in range(m + 1)] for _ in range(n + 1)]
res = 0

for i in range(1, n + 1):
    for j in range(1, m + 1):
        s[i][j] = arr[i - 1][j - 1] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]

for k in range(T):
    res = s[pos[k][2]][pos[k][3]] - s[pos[k][0] - 1][pos[k][3]] - s[pos[k][2]][pos[k][1] - 1] + s[pos[k][0] - 1][pos[k][1] - 1]
    print(res) 