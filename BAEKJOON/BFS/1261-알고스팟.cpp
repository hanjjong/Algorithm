#include <iostream>
#include <queue>

int n, m;
int arr[101][101];
int visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0 ,0};
std::queue<std::pair<int, int> > q;

int main(){
    std::cin >> n >> m;
    for (int i = 0; i < m; i++){
        std::string input;
        std::cin >> input;
        for (int j = 0; j < n; j++)
            arr[i][j] = input[j] - '0';       
    }
    for (int i = 0; i < 100; i++)
        std::fill(visited[i], visited[i] + 102, 2147483647);
    q.push({0, 0});
    visited[0][0] = 0;
    while (!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] == 0) continue;
            if ((visited[nx][ny] > visited[cx][cy]) && arr[nx][ny] == 0) {
                visited[nx][ny] = visited[cx][cy];
                q.push({nx, ny});
            }
            else if ((visited[nx][ny] > visited[cx][cy] + 1) && arr[nx][ny] == 1){
                visited[nx][ny] = visited[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    std::cout << visited[m - 1][n - 1];
}