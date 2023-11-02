#include <iostream>
using namespace std;
#include <queue>

int N, M;
int arr[301][301];
int tmp[301][301];
int visited[301][301] = {0, };

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int check(int r, int c)
{
    int a = 0, b = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i=0; i < 4; i++)
        {
            int nr = cr + dx[i];
            int nc = cc + dy[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < M)
            {
                if (visited[nr][nc] != 1 && arr[nr][nc] != 0)
                {
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                } 
            }
        }
    }
    return (0);
}

int icebreaking()
{
    int sea = 0;
    int nx = 0;
    int ny = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tmp[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
                continue;
            sea = 0;
            for (int k = 0; k < 4; k++)
            {
                nx = i + dx[k];
                ny = j + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue ;
                if (arr[nx][ny] == 0)
                    sea++;
            }
            int cnt = arr[i][j] - sea;
            if (cnt > 0)
                tmp[i][j] = cnt;
        }
    }
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
    return (0);
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int time = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    while (true)
    {
        int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] != 1 && arr[i][j] != 0) 
                {
					check(i, j);
					cnt++;
				}
			}
		}
        if (cnt == 0)
        {
            cout << 0;
            break ;
        }
        else if (cnt >= 2)
        {
            cout << time;
            break ;
        }
        time++;
        icebreaking();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                visited[i][j] = 0;
            }
        }
    }

}