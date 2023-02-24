import sys

num = int(input())

lis = list(set(sys.stdin.readline().strip() for _ in range(num)))
new = []


for i in range(1,51) :
    t = []
    if len(lis) == 0 : break
    for j in lis :
        if len(j) == i :
            t.append(j)
    lis = [x for x in lis if len(x) != i]
    t.sort()
    new.extend(t)

for i in range(len(new)):
    print(new[i])