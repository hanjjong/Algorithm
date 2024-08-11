#include <iostream>
#include <queue>

int arr[1000003];
int visited[1000003];
std::queue<int> q;

int subin;
int bro;
int dx[] = {1, -1};

int main(){

    std::cin >> subin >> bro;
    q.push(subin);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 3; i++){
            int nx;
            if (i < 2)
                nx = cur + dx[i];     
            else if (i == 2)
                nx = cur * 2;

            if (nx < 0 || nx >= 100000) continue;
            if (i < 2) {
                if (visited[nx] > visited[cur] + 1 || visited[nx] == 0){
                    visited[nx] = visited[cur] + 1;
                    q.push(nx);
                }
            }
            else if (i == 2){
                if (visited[nx] > visited[cur] || visited[nx] == 0){
                    visited[nx] = visited[cur];
                    q.push(nx);
                }
            }
        }
    }
    std::cout << visited[bro];
}