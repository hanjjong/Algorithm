#include <iostream>
using namespace std;
#include <vector>

int arr[5][5] = {0, };
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
                printf("111\n");
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
                printf("222\n");
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
            if (i == 4)
            {
                printf("333\n");
                bingo++;
            }
        }
        else
            break ;
    }
    j = 4;
    i = 4;
    while (j >= 0)
    {
        if (arr[i][j] == 0)
        {
            i--;
            j--;
            if (i == 0)
            {
                printf("444\n");
                bingo++;
            }
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
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            scanf("%d",&arr[i][j]);
    }
    while (count--)
    {
        cin >> num;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (arr[i][j] == num)
                    arr[i][j] = 0;
                is_bingo();
            }
        }
        printf("bingo : %d\n", bingo);
        if (bingo >= 3)
        {  
            int o;
            o = 25 - count;
            cout << o;
        }
    }
}
