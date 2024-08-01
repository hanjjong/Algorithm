#include <iostream>
#include <queue>
#include <algorithm>

int N, flag;
int w, h;
int fireVisited[1002][1002];
int visited[1002][1002];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    std::cin >> N;
    std::string input;
    while(N--){
        flag = 0;
        std::queue<std::pair<int, int> > sq;
        std::queue<std::pair<int, int> > fq;
        std::cin >> w >> h;
        for (int i = 0; i < h; i++){
            std::cin >> input;
            for (int j = 0; j < w; j++){
                if (input[j] == '#'){
                    visited[i][j] = -2;
                    fireVisited[i][j] = -2;
                }
                else if (input[j] == '@'){
                    fireVisited[i][j] = -1;
                    visited[i][j] = 0;
                    sq.push({i, j});
                }
                else if (input[j] == '*'){
                    fireVisited[i][j] = 0;
                    visited[i][j] = -1;
                    fq.push({i, j});
                }
                else {
                    fireVisited[i][j] = -1;
                    visited[i][j] = -1;
                }
            }
        }
        while (!fq.empty()){
            int cx, cy, nx, ny;
            cx = fq.front().second;
            cy = fq.front().first;
            fq.pop();
            for (int i = 0; i < 4; i++){
                nx = cx + dx[i];
                ny = cy + dy[i];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (fireVisited[ny][nx] == -2 || fireVisited[ny][nx] != -1) continue;
                fq.push({ny, nx});
                fireVisited[ny][nx] = fireVisited[cy][cx] + 1;
            }
        }
        while (!sq.empty()){
            int cx, cy, nx, ny;
            cx = sq.front().second;
            cy = sq.front().first;
            sq.pop();
            for (int i = 0; i < 4; i++){
                nx = cx + dx[i];
                ny = cy + dy[i];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h){
                    flag = 1;
                    std::cout << visited[cy][cx] + 1 << "\n";
                    break;    
                } 
                if (((visited[cy][cx] + 1 < fireVisited[ny][nx]) || fireVisited[ny][nx] == -1) && visited[ny][nx] == -1){
                    sq.push({ny, nx});
                    visited[ny][nx] = visited[cy][cx] + 1;
                }
            }
            if (flag == 1) break;
        }
        if (flag == 0)
            std::cout << "IMPOSSIBLE\n";
    }
}