#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

int M, N, H;
int cx, cy, cz, nx, ny, nz, flag;
int dx[] = {1, -1 , 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int arr[101][101][101];
int visited[101][101][101];

int main(){
    std::queue<std::pair< std::pair<int, int>, int> > q;
    memset(visited, -1, sizeof(visited));

    std::cin >> M >> N >> H;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                std::cin >> arr[i][j][k];
                if (arr[i][j][k] == 1){
                    q.push({{i, j}, k});
                    visited[i][j][k]++;
                }
                if (arr[i][j][k] != 1)
                    flag = 1;
            }
        }
    }
    if (flag == 0){
        std::cout << "0";
        return 0;
    }
    while (!q.empty()){
        cx = q.front().second;
        cy = q.front().first.second;
        cz = q.front().first.first;
        q.pop();
        for (int i = 0; i < 6; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];
            nz = cz + dz[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
            if (visited[nz][ny][nx] >= 0 || arr[nz][ny][nx] == -1) continue;
            visited[nz][ny][nx] = visited[cz][cy][cx] + 1;
            q.push({{nz, ny} ,nx});
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                if (arr[i][j][k] == 0 && visited[i][j][k] == -1){
                    std::cout << "-1";
                    return 0;
                }
                ans = std::max(ans, visited[i][j][k]);
            }
        }
    }
    std::cout << ans;
}
