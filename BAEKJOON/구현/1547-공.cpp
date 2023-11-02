#include <iostream>
using namespace std;

int num;
int cup1;
int cup2;
int tmp1;
int tmp2;
int arr[3] = {1, 2, 3};
int main()
{
    cin >> num;
    while (num--)
    {
        cin >> cup1 >> cup2;
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] == cup1)
                tmp1 = i;
            if (arr[i] == cup2)
                tmp2 = i;
        }
        swap(arr[tmp1], arr[tmp2]);
    }
    cout << arr[0];
}