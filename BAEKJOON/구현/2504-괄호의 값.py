input = list(input())
stack = []
sum = 0
count = 1
for i in range(len(input)):
    if input[i] == '(':
        stack.append(input[i])
        count *= 2
    elif input[i] == '[':
        stack.append(input[i])
        count *= 3
    else :
        if input[i] == ')':
            if not stack or stack[-1] != '(':
                sum = 0
                break
            elif input[i - 1] == '(' and stack[-1] == '(':
                sum += count
            stack.pop()
            count //= 2 
        elif input[i] == ']':
            if not stack or stack[-1] != '[':
                sum = 0
                break
            elif input[i - 1] == '[' and stack[-1] == '[':
                sum += count
            stack.pop()
            count //= 3


if stack:
    print(0)
else :
    print(sum)
