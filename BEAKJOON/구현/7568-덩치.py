import sys

T = int(sys.stdin.readline())

array = [[0] * 2 for _ in range(T)] 
rank = [ 1 for _ in range(T)]
for i in range(T):
    array[i][0], array[i][1] = (map(int, input().split()))

for x in range(T):
    for y in range(T):
        if array[x][0] > array[y][0] and array[x][1] > array[y][1]:
            rank[y] = rank[y] + 1
for j in rank:
    print(j , end = ' ')
