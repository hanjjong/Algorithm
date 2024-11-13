#include <iostream>
#include <vector>
#include <algorithm>

int n, m, value;
int is_used[10001];
int arr[9];
std::vector<int> v;

void recul(int num) {
    if (num == m) {
        for (int i = 0; i < m; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return ;
    }

    for (auto i = v.begin(); i != v.end(); ++i) {
        if (!is_used[*i]){
            arr[num] = *i;
            is_used[*i] = 1;
            recul(num + 1);
            is_used[*i] = 0;
        }
    }
    return ;
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++){
        std::cin >> value;
        v.push_back(value);
    }
    sort(v.begin(), v.end());
    recul(0);
}