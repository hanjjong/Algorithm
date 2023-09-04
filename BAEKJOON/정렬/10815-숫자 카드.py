import sys

num = int(sys.stdin.readline().strip())
card = list(map(int,sys.stdin.readline().strip().split()))

num1 = int(sys.stdin.readline().strip())
card_check = list(map(int,sys.stdin.readline().strip().split()))

def search(array, target, start, end):
    while start <= end :
        mid = (start + end) // 2
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid - 1
        elif array[mid] < target:
            start = mid + 1
    return None
    
card.sort()

for i in card_check:
    result = search(card, i, 0 , num - 1)
    if result != None:
        print(1, end = ' ')
    else:
        print(0, end = ' ')