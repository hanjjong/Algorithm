#include <iostream>
using namespace std;
#include <vector>

int arr[7][7];
int num;
int bingo = 0;

int is_bingo()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] != 0)
                break ;
            if (j == 4)
            {
                bingo++;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[j][i] != 0)
                break ;
            if (j == 4)
            {
                bingo++;
            }
        }
    }
    int i = 0;
    int j = 0;
    while (j < 5)
    {
        if (arr[i][j] == 0)
        {
            i++;
            j++;
            if (i == 5)
                bingo++;
        }
        else
            break ;
    }
    j = 4;
    i = 0;
    while (i < 5)
    {
        if (arr[i][j]  == 0)
        {
            j--;
            i++;
            if (i == 5)
                bingo++;
        }
        else
            break ;
    }
    return (0);
}

int main()
{
    int count = 25;
    int cnt = 0;
    int res = 0;
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    }
    while (count--)
    {
        cnt++;
        cin >> num;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                bingo = 0;

                if (arr[i][j] == num)
                    arr[i][j] = 0;
                is_bingo();
            }
        }
        if ((bingo >= 3) && flag == 0)
        {  
            res = cnt;
            flag = 1;
            cout << cnt;
        }
    }
}
