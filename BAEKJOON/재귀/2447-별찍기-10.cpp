#include <iostream>

int N;
char arr[2222][2222];

void recur(int x, int y, int n){
    if (n == 1){
        arr[x][y] = '*';
        return ;
    }
    int div = n / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (i == 1 && j == 1)
                continue;
            recur(x + i * div, y + j * div, div);
        }
    }
}

int main(){
    std::cin >> N;
    recur (0,0,N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (!arr[i][j])
                std::cout <<" ";
            else
                std::cout << arr[i][j];
        }            
        std::cout << "\n";
    }
}

