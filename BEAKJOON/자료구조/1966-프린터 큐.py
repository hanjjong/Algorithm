import sys
from collections import deque

queue = deque()
def que():
    global count
    while queue:
        x = queue.popleft()
        for i in queue:
            print(i)
            if x < i:
                queue.append(x)
                count += 1
            else :
                return i
        

num = int(input())

important = []
print_out = []
for i in range(num):
    count = 1
    queue.clear()
    n, when = map(int,sys.stdin.readline().strip().split())
    important.append(list(map(int, sys.stdin.readline().strip().split())))

    for j in range(n):
        queue.append(important[i][j])
    print(queue)
    if que() == important[when]:
        print_out.append(count)
        print(count)

for i in range(num):
    print(print_out[i])
