import sys

num = int(input())

array = list(map(int, sys.stdin.readline().strip().split()))
x = int(input())

array.sort()
i, j ,sum, count= 0, len(array) - 1, 0, 0
start = array[i]
end = array[j]

while i < j:
    sum = array[i] + array[j]
    if sum == x:
        count+=1
        i += 1
        j -= 1
    elif sum < x:
        i += 1
    else:
        j -= 1
print(count)