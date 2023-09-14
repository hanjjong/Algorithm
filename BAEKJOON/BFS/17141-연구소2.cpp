#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[51][51];

int dx[4] = {1, -1 ,0 ,0};
int dy[4] = {0, 0 ,1 ,-1};

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    

}