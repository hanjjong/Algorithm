import sys

num, kill = map(int, sys.stdin.readline().split())

array = [x + 1 for x in range(num)]
index = []
count = kill - 1
for x in range(num):
    if len(array) > count:
        index.append(array.pop(count))
        count += kill - 1
    elif len(array) <= count:
        count = count%len(array)
        index.append(array.pop(count))
        count += kill - 1
print("<", ", ".join(str(i) for i in index),">",sep = "")