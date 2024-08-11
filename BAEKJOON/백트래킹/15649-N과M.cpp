#include <iostream>

int n, m;
int arr[10];
int isused[10];


int func(int k){
    if (k == m){
        for (int i = 0; i < m; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return 1;
    }
    for (int i = 1; i < n + 1; i++){
        if (!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
    return 0;
}


int main(){
    std::cin >> n >> m;
    func(0);
}