#include <iostream>
#include <string>


int arr[10];
int N;
long res = 1;
int main(){
    for (int i = 0; i < 3; i++){
        std::cin >> N;
        res *= N;
    }
    std::string num = std::to_string(res);
    for (auto c : num)
    {
        arr[c - '0']++;
    }
    for (auto c : arr){
        std::cout << c << " ";
    }
} 