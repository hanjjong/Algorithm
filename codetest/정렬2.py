num = int(input())

student = []
for i in range(num):
    data = input().split()
    student.append(data[0], data[1])

student = sorted(student, key = lambda student : student[1])

for i in range(num):
    print(student[0], end = ' ')
