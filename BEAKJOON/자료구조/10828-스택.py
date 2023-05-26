import sys

stack = []

T = int(input())
for i in range(T):
    word = sys.stdin.readline().split()
    command = word[0]
    if command == 'push':
        num = word[1]
        stack.append(int(num))
    elif command == 'top':
        if not stack:
            print(-1)
        else:
            print(stack[-1])
    elif command == 'size':
        print(len(stack))
    elif command == 'empty':
        if not stack:
            print(1)
        else:
            print(0)
    elif command == 'pop':
        if not stack:
            print(-1)
        else :
            print(stack.pop())
        
