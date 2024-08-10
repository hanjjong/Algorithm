#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[501][501];
int visited[501][501];
int cnt;
int p_size;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void    check(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;
    int sz = 1;
    while (!q.empty())
    {

        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = cr + dx[i];
            int nc = cc + dy[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m)
            {
                if (visited[nr][nc] != 1 && arr[nr][nc] != 0)
                {
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                    sz++;
                }
                if (sz >= p_size){
                    p_size = sz;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && arr[i][j] == 1)
            {
                check(i , j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    cout << p_size;
}