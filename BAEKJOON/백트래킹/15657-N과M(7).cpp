#include <iostream>
#include <vector>
#include <algorithm>

int n, m, value;
int is_used[10];
int arr[10];
int qwer[10];
int never_use[10];

void recul(int num) {
    if (num == m) {
        for (int i = 0; i < m; i++) {
            std::cout << qwer[arr[i]] << " ";
        }
        std::cout << "\n";
        return ;
    }
    int st = 0;
    if (num != 0) st = arr[num - 1];
    for (int i = st; i < n; i++) {
        // if (!is_used[i]){
            arr[num] = i;
            // is_used[i] = 1;
            recul(num + 1);
            // is_used[i] = 0;
        // }
    }
    return ;
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) std::cin >> qwer[i];
    std::sort(qwer, qwer + n);
    recul(0);
}