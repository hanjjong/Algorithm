from collections import deque
import sys

T = int(input())
d = deque()
for i in range(T):
    word = sys.stdin.readline().split()
    command = word[0]
    if command == 'push_front':
        num = word[1]
        d.appendleft(int(num))
    elif command == 'push_back':
        num = word[1]
        d.append(int(num))
    elif command == 'pop_front':
        if not d:
            print(-1)
        else :
            print(d.popleft())
    elif command == 'pop_back':
        if not d:
            print(-1)
        else :
            print(d.pop())
    elif command == 'size':
        print(len(d))
    elif command == 'empty':
        if not d:
            print(1)
        else :
            print(0)
    elif command == 'front':
        if not d:
            print(-1)
        else :
            print(d[0])
    elif command == 'back':
        if not d:
            print(-1)
        else :
            print(d[-1])
