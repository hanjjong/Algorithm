#include <iostream>


int isused[14];
int arr[7];
int input[14];
int num_count;

void func(int num){
    if (num == 6){
        for (int i = 0; i < 6; i++)
            std::cout << input[arr[i]] << " ";
        std::cout << "\n";
        return ;
    }
    int st = 0;
    if (num != 0) st = arr[num - 1];
    for (int i = st; i < num_count; i++){
        if (!isused[i]){
            arr[num] = i;
            isused[i] = 1;
            func(num + 1);
            isused[i] = 0;
        }
    }

    return ;
}

int main(){
    while (1){
        std::cin >> num_count;
        if (num_count == 0)
            break;
        for (int i = 0; i < num_count; i++){
            std::cin >> input[i];
        }
        func(0);
        std::cout << "\n";
    }
}