import sys

num = int(input())
iarray = list((input().split() for _ in range(num)))

for i in range(num):
    iarray[i][0] = int(iarray[i][0])

cmp = []

cmp.extend(iarray)
cmp.sort(key = lambda x:x[0])

for i in range(num):
    print(cmp[i][0], end =' ')
    print(cmp[i][1])

