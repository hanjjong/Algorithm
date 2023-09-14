#include <iostream>
using namespace std;

int win[1002];
int N;

int main()
{
    win[1] = 2;
    win[2] = 1;
    win[3] = 2;
    win[4] = 1;
    cin >> N;
    for (int i = 5; i <= N; i++)
    { 
        if (win[i - 1] == 2 || win[i - 3] == 2 || win[i - 4] == 2)
        {
            win[i] = 1;
        }
        else
            win[i] = 2;
    }
    if (win[N] == 1)
        cout << "SK";
    else 
        cout << "CY";
}

//