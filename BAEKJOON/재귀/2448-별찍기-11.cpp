#include <iostream>

int N;

char arr[1024 * 3 + 2][(2 * 1024 * 3) + 2];

int fill(int x, int y){
    arr[x][y] = '*';
    arr[x + 1][y - 1] = '*';
    arr[x + 1][y + 1] = '*';
    for (int i = y - 2; i < y + 3; i++){
        arr[x + 2][i] = '*';
    }
    return 1;
}

int recul(int n, int x, int y){
    if (n == 3){
        fill(x, y);
        return 0;
    }
    int ns = n / 2;
    recul(ns, x, y);
    recul(ns, x + ns, y - ns);
    recul(ns, x + ns, y + ns);
    return 0;
}


int main(){
    std::cin >> N;

    recul(N, 0, N - 1);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 2 * N - 1; j++){
            if  (arr[i][j] == '*'){
                std::cout << "*";
            }
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
}