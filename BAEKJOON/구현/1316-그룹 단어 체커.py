import sys

T = int(input())

k = T
for i in range(T):
    word = sys.stdin.readline().strip()
    for j in range(0, len(word) - 1):
        if word[j] == word[j + 1]:
            pass
        elif word[j] in word[j+1:]:
            k-=1
            break
print(k)
