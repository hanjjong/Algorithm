#include <iostream>
using namespace std;

int n; //세로크기
int m; //가로크기
int x; //주사위를 놓은 곳의 좌표
int y;
int k; // 명령의 개수
int dice[7] = {0, 0, 0, 0, 0, 0};
int map[21][21];
int cmd;

void    output()
{
    if(map[x][y] == 0)
    {
        map[x][y] = dice[5];
    }
    else
    {
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
    cout << dice[0] << "\n";
}

int    check_move(int  y, int x)
{
    if (y >= m || y < 0)
        return (0);
    if (x >= n || x < 0)
        return (0);
    return (1);
}

void    dice_move()
{
    if (cmd == 1 && check_move(y + 1, x))
    {
        int tmp = 0;
        tmp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
        y += 1;
        output();
    }
    else if (cmd == 2 && check_move(y - 1, x))
    {
        int tmp = 0;
        tmp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[2];
        dice[2] = tmp;
        y -= 1;
        output();
    }
    else if (cmd == 3 && check_move(y, x - 1))
    {
        int tmp = 0;
        tmp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[3];
        dice[3] = tmp;
        x -= 1;
        output();
    }
    else if (cmd == 4 && check_move(y, x + 1))
    {
        int tmp = 0;
        tmp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[4];
        dice[4] = tmp;
        x += 1;
        output();
    }
}

int main(void)
{
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i< n; i++)
    {
        for (int j = 0; j<m; j++)
            cin >> map[i][j];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> cmd;
        dice_move();
    }
    
}