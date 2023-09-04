#include <iostream>
#include <list>
using namespace std;

int N;
int arr[1000][3];
int cnt = 0;;

int main(void)
{
    int strike = 0;;
    int ball = 0;;
    int flag = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 123; i < 1000; i++)
    {
        flag = 1;
        for (int j = 0; j < N; j++)
        {
            strike = 0;
            ball = 0;

            if (i / 100 == arr[j][0] / 100)
                strike++;
            else if (i / 100 == (arr[j][0] / 10) % 10)
                ball++;
            else if (i / 100 == arr[j][0] % 10)
                ball++;
            if ((i / 10) % 10 == (arr[j][0] / 10) % 10)
                strike++;
            else if ((i / 10) % 10 == arr[j][0] / 100)
                ball++;
            else if ((i / 10) % 10 == arr[j][0] % 10)
                ball++;
            if (i % 10 == arr[j][0] % 10)
                strike++;
            else if (i % 10 == (arr[j][0] / 10) % 10)
                ball++;
            else if (i % 10 == arr[j][0] / 100)
                ball++;
            if (strike != arr[j][1] || ball != arr[j][2] || i / 100 == 0 || (i / 10) % 10 == 0 || i % 10 == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1 && (i / 100) != ((i / 10) % 10) && ((i / 10) % 10) != (i % 10) && (i / 100) != (i % 10))
            cnt++;
    }
    cout << cnt;
}