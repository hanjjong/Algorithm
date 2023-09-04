import sys

n, m = list(map(int, input().split()))
array = list(map(int,sys.stdin.readline().strip().split()))

start = max(array)
end = sum(array)

while start <= end:
    mid = (start + end) // 2

    count = 1
    each_ray = 0
    for i in array:
        if each_ray + i <= mid:
            each_ray += i
        else:
            each_ray = i
            count +=1
    if count <= m:
        end = mid - 1
    else:
        start = mid + 1

print(start)
    
