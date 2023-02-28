import sys

num = int(input())

lope = []
weight = []
for i in range(num):
    lope.append(int(sys.stdin.readline().strip()))

lope.sort()

for i in range(num):
    weight.append(lope[i] * (num - i))
print(max(weight))