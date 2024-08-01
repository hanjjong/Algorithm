#include <iostream>

int arr[26];
int main()
{
    std::string s;
    std::cin >> s;
    for (auto c : s){
        arr[c - 'a']++;
    }
    for (auto c : arr){
        std::cout << c << " ";
    }

}