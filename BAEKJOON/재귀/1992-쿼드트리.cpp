#include <iostream>

int N;
int arr[65][65];

void input(void)
{
    std::cin >> N;
    for (int i =0; i < N; i++){
        std::string str;

        std::cin >> str;
        for (int j = 0; j < N; j++){
            arr[i][j] = str[j] - '0';
        }
    }
}

int check(int x, int y, int size){
    int num = arr[x][y];
    for (int i = x; i < x+size; i++){
        for (int j = y; j < y+size; j++){
            if (num != arr[i][j])
                return 0;
        }
    }
    std::cout << num;
    return 1;
}

void recur(int x, int y, int size){
    if (check(x, y, size)){
        return ;
    }
    std::cout << "(";
    recur(x, y, size/2);
    recur(x, y + size/2, size/2);
    recur(x + size/2, y, size/2);
    recur(x + size/2, y + size/2, size/2);
    std::cout << ")";
}

int main(void)
{
    input();
    recur(0, 0, N);
    return (0);
}