#include <iostream>

int N, cnt_white, cnt_blue;
int arr[130][130];

int check(int x, int y, int size){
    int color = arr[x][y];
    for(int i = x; i < x+size; i++){
        for(int j = y; j < y + size; j++){
            if (color != arr[i][j])
                return 0;
        }
    }
    if(color == 1)
        cnt_blue++;
    else
        cnt_white++;
    return 1;
}

void recur(int x, int y, int size){
    if (check(x, y, size)){
        return ;
    }

    recur(x, y, size/2);
    recur(x+size/2, y, size/2);
    recur(x, y+size/2, size/2);
    recur(x+size/2, y+size/2, size/2);
    return ;
}

int main(){
    std::cin >> N;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            std::cin >> arr[i][j];
        }
    }
    recur(0, 0, N);
    std::cout << cnt_white << "\n" << cnt_blue;
    return 0;
}

