import sys
input = sys.stdin.readline()

count1 = 0
count2 = 0

for i in range(len(input) - 1) :
    if input[i] != input[i+1] and input[i] == "0" :
        count1 += 1
    elif input[i] != input[i+1] and input[i] == "1" :
        count2 += 1

print(min(count1, count2))