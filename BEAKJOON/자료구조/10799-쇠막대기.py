lazer = input()

stack = []
count = 0

for pos in range(len(lazer)):
    if lazer[pos] == '(':
        stack.append(lazer[pos])
    else :
        if lazer[pos - 1] == '(':
            stack.pop()
            count += len(stack)
        else:
            stack.pop()
            count+=1

print(count)
