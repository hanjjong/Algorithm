import sys

n, m = list(map(int, sys.stdin.readline().strip().split()))
array = []

for i in range(n):
    array.append(int(sys.stdin.readline().strip()))


start = max(array)
end = sum(array)

while start <= end:
    mid = (start + end) // 2
    count = 1
    wallet = 0
    for i in array:
        if wallet + i <= mid:
            wallet+=i
        else:
            wallet = i
            count+=1
    if count <= m:
        end = mid - 1
    else:
        start = mid + 1

print(start)