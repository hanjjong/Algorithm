import sys

num = int(input())

list = [int(sys.stdin.readline().strip()) for _ in range(num)]
list.sort()

for i in range(num):
    print(list[i])