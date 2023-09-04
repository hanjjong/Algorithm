import sys
sys.setrecursionlimit(10**5)

def board_check(pos):
    for index in range(pos):
        if pos - index == abs(board[pos] - board[index]):
            return 0
        elif board[index] == board[pos]:
            return 0
    return 1


def create_board(pos, num):
    global count

    if pos == num:
        count = count + 1
        return 1
    
    for value in range(num):
        board[pos] = value
        if board_check(pos) == 1:
            create_board(pos + 1, num)

##    while value < num:
##        board[pos] = value
##        if board_check(pos) == 1:
##            create_board(pos + 1, num)
##       value += 1

num = int(sys.stdin.readline().strip())

board = [-1] * num
count = 0
create_board(0, num)
print(count)