## 이진 탐색 방법
import sys

def search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid - 1
        else :
            start = mid + 1
        return None
    
num = int(sys.stdin.readline().strip())
array = list(map(int, input().split()))
array.sort()

m = int(input())
x = list(map(int, input().split()))

for i in x:
    result = search(array, i , 0, num - 1)
    if result != None:
        print('yes', end =' ')
    else :
        print('no', end = ' ')



