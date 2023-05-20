import sys

tnum = int(sys.stdin.readline())
for i in range(tnum):
    k = int(sys.stdin.readline())
    n = int(sys.stdin.readline())
    zero_floor = list(range(1, n+1))

    for x in range(k):
        for y in range(1, n):
            zero_floor[y] += zero_floor[y-1]
    print(zero_floor[-1])