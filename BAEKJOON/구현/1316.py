num = int(input())

def check(str, c, pos):
    for i in range(pos):
        if str[i] == c :
            return 0
    return 1

arr = {}
count = 0
for i in range(num):
    arr[i] = input()
for i in range(len(arr)):
    if(len(arr[i])==1):
        count+=1
    j = 0
    while j != len(arr[i]) - 1:
        if check(arr[i], arr[i][j], j) == 1:
            while arr[i][j] == arr[i][j + 1]:
                j+=1
                if j == len(arr[i]) - 1:
                    break
        if check(arr[i], arr[i][j], j)==0:
            break
        j+=1
        if j >= len(arr[i]) - 2 :
            print(arr[i])
            count +=1
print(count)