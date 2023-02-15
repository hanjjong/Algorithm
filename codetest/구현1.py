size = int(input())
plans = input().split()

x,y = 1, 1
nx, ny =0, 0
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
move_types = ['R', 'L', 'U', 'D']

for plan in plans:
    for i in range(len(move_types)):
        if plan == move_types[i]:
            nx = x + dx[i]
            ny = y + dy[i]
    if (nx < 1 or ny < 1 or nx > size or ny > size):
        continue
    x = nx
    y = ny

print(x, y)