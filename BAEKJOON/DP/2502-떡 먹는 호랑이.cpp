#include <iostream>
using namespace std;


int arr[2];
int cal[31];
int day, num;
int a, b;
int flag;
int main()
{
    a = 1;
    b = 1;
    cin >> day >> num;
    for (int a = 1; a < num; a++)
    {
        for (int b = a; b < num; b++)
        {
            for (int i = 2; i < day; i++)
            {
                cal[0] = a;
                cal[1] = b;
                cal[i] = cal[i - 1] + cal[i - 2];
            }
            if (cal[day - 1] == num)
            {
                cout << a << "\n" << b;
                return (0);
            }
        }

    }
}