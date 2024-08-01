#include <iostream>


int arr[26];
int N;
int flag;
int main(){
    std::cin >> N;
    while (N--){
        flag = 0;
        for (int i = 0; i < 26; i++){
            arr[i] = 0;
        }
        std::string str1, str2;
        std::cin >> str1 >> str2;
        for (auto i : str1)
            arr[i - 'a']++;
        for (auto i : str2){
            if (arr[i - 'a'] == 0){
                std::cout << "Impossible" << "\n";
                flag = 1;
                break ;
            }
            else 
                arr[i - 'a']--;
        }
        for (auto i : arr){
            if (i != 0 && flag != 1){
                std::cout << "Impossible" << "\n";
                flag = 1;
                break ;
            }
        }
        if (!flag)
            std::cout << "Possible" << "\n";
    }
}