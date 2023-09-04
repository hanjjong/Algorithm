#include <iostream>
using namespace std;

int T;
int W;
int v;
int arr[1001][1001];

int main()
{
    cin >> T >> W;
    for (int i = 0; i < T; i++)
    {
        cin >> v;
        if (v == 1){
            arr[0][i] = 1;
            arr[1][i] = 0;
        }
        else {
            arr[1][i] = 1;
            arr[0][i] = 0;
        }
    }
    
}
