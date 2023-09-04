import sys

num = int(int(sys.stdin.readline().strip()))

array = [int(sys.stdin.readline().strip()) for _ in range(num)]
after = []

after = sorted(array)
maxd = 0
for i in range(1, num):
    for j in range(i + 1):
        if array[i] == after[j]:
            maxd = max(maxd, i - j)
print(maxd + 1)