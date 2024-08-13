#include <iostream>

//  3  1
int n, m;
int is_used[9];
int arr[9];

void recul(int num) {
    if (num == m) {
        for (int i = 0; i < m; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return ;
    }

    // int st = 1;
    // if(num != 0) st = arr[num - 1];
    for (int i = 1; i <= n; i++) {
        if (!is_used[i]){
            arr[num] = i;
            // is_used[num + 1] = 1;
            recul(num + 1);
            // is_used[num + 1] = 0;
        }
    }
    return ;
}

int main() {
    std::cin >> n >> m;
    recul(0);
}