num = int(input())

array = []
for i in range(num):
    array.append(int(input()))

array.sort(reverse=True)
for i in range(num):
    print(array[i], end = ' ')