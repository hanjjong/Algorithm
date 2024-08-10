#include <iostream>
#include <queue>

int N, len, cnt;
int afterx, aftery, beforex, beforey, nx, ny;
int result;
int flag;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, 2, 1, -1, -2};
int visited[301][301];

void clearQueue(std::queue<std::pair<int, int> > &q) {
    std::queue<std::pair<int, int> > empty;
    std::swap(q, empty);
}

void check(int i, int j){
    flag = 0;
    result = 0;
    cnt = 0;
    for (int q = 0; q < 301; q++){
        std::fill(visited[q], visited[q] + 301, -1);
    }
    std::queue<std::pair<int, int> > q;
    q.push({i, j});
    visited[i][j] = 0;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second; 
        q.pop();
        for(int iter = 0; iter < 8; iter++){
            nx = qx + dx[iter];
            ny = qy + dy[iter];
            if (nx < 0 || nx >= len || ny < 0 || ny >= len) continue;
            if (visited[nx][ny] >= 0) continue;
            visited[nx][ny] = visited[qx][qy] + 1;
            q.push({nx, ny});
        }
    }
    std::cout << visited[nx][ny] << "\n";
}

int main(){
    std::cin >> N;
    for (int p = 0; p < N; p++){
        std::cin >> len;
        std::cin >> beforex >> beforey;
        std::cin >> afterx >> aftery;

        check(beforex, beforey);
    }
}