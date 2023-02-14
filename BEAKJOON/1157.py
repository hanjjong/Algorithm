input = input()
input = input.lower()
d = [0 for _ in range(26)]

for i in range(len(input)):
    d[int(ord(input[i]) - ord('a'))] += 1

result = 0
count = 0
result = max(d)
for i in range(len(d)):
    if result == d[i]:
        count+=1
if count >= 2:
    print("?")
else:
    for i in range(len(d)):
        if result == d[i]:
            print(chr(i + ord('A')))
