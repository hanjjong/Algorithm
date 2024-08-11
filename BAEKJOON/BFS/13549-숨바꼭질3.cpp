#include <iostream>
#include <queue>

int arr[100003];
int visited[100003];
std::queue<int> q;

int subin;
int bro;
int dx[] = {1, -1};

int main(){

    std::cin >> subin >> bro;
    std::fill(visited, visited + 100001, 2147483647); // 방문 배열 초기화
    visited[subin] = 0;
    q.push(subin);
    while (!q.empty()){
        int cur = q.front();
        q.pop();

        if (cur == bro) {  // 동생을 찾으면 종료
            std::cout << visited[cur];
            return 0;
        }
        for (int i = 0; i < 3; i++){
            int nx;
            if (i == 0)
                nx = cur * 2;
            else
                nx = cur + dx[i - 1];     

            if (nx < 0 || nx >= 100001) continue;
            if (i > 0) {
                if (visited[nx] > visited[cur] + 1){
                    visited[nx] = visited[cur] + 1;
                    q.push(nx);
                }
            }
            else if (i == 0){
                if (visited[nx] > visited[cur]){
                    visited[nx] = visited[cur];
                    q.push(nx);
                }
            }
        }
    }
}