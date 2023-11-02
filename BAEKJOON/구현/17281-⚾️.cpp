#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int ining[51][10];
int player[10];
bool Select[10];
int pos[10];
int num[10];
int Max = -1;
vector<int> V;

void input()
{
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=9;j++)
        {
            cin >> ining[i][j];
        }
    }
}

void play()
{
    int hitter = 1, score = 0;
    for (int i=1; i<= N;i++)
    {
        int outcount = 0;
        while (1)
        {
            if (ining[i][player[hitter]] == 0) //아웃
            {
                hitter++;
                if (hitter >= 10) hitter = 1;
                outcount++;
                if (outcount == 3)
                {
                    for (int j = 1; j <= 9; j++) pos[j] =0;
                    break;
                }
            }
            else{ //유효타
                for (int j = 1; j <= 9; j++)
                {
                    if (pos[j] > 0 || j == player[hitter]){
                        pos[j] += ining[i][player[hitter]];
                        if (pos[j] >= 4)
                        {
                            pos[j] = 0;
                            score++;
                        }
                    }
                }
                hitter++;
                if (hitter >= 10) hitter = 1;
            }
        }
    }
    if (Max < score)Max = score;
}

void game(int num)
{
    if (num > 9)
    {
        play();
        return ;
    }
    for (int i = 2; i <= 9; i++)
    {
        if (!Select[i]){
            player[num] = i;
            Select[i] = true;
            if (num == 3)
                game(num + 2);
            else game(num + 1);
            Select[i] = false;
        }
    }
}

int main()
{
    Select[1] = true;
    player[4] = 1;
    cin >> N;
    input();
    game(1);

    cout << Max << "\n";
    return 0;
}