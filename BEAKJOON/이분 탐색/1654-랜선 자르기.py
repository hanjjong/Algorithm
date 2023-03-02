import sys
import time
n, m = list(map(int, input().split()))

array = []

for i in range(n):
    array.append(int(sys.stdin.readline().strip()))

start = 1
end = (max(array))
count = 0

while start <= end:
    count = 0
    mid = (start + end) // 2
    for i in array:
        i = i // mid
        count += i
    if count < m:
        end = mid - 1
    else:
        start = mid + 1

print(end)