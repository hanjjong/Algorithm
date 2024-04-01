#include <iostream>
#include <algorithm>

int arr[10];
std::string N;
int main(){
    std::cin >> N;
    for (auto i : N)
        arr[i - '0']++;
    arr[6] += arr[9];
    arr[6]++;
    arr[9] = 0;
    arr[6] /= 2;
    std::cout << *std::max_element(arr, arr + 10) << "\n";
}