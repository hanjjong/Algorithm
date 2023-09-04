import sys
from collections import deque

num = int(input())

for i in range(num):
    n, m = list(map(int, input().split()))
    queue = deque(list(map(int,sys.stdin.readline().strip().split())))
    count = 0
    while queue:
        max_q = max(queue)
        x = queue.popleft()
        m -= 1
        if x == max_q:
            count += 1
            if m < 0 :
                print(count)
                break
        else:
            queue.append(x)
            if m < 0:
                m = len(queue) - 1