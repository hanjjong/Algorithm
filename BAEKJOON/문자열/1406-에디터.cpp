#include <iostream>
#include <list>

std::list<char> arr;
int main(){

    int N = 0;
    std::string origin;

    std::cin >> origin;
    std::cin >> N;
    for (auto c : origin)
        arr.push_back(c);

    auto cursor = arr.end();
    char command;

    while(N--){
        std::cin >> command;
        if (command == 'P'){
            char c;
            std::cin >> c;
            arr.insert(cursor, c);
        }
        else if (command == 'L'){
            if (cursor != arr.begin())
                cursor--;
        }
        else if (command == 'D'){
            if (cursor != arr.end())
                cursor++;
        }
        else if (command == 'B'){
            if (cursor != arr.begin()){
                cursor--;
                cursor = arr.erase(cursor);
            }
        }
    }
    for (auto c : arr){
            std::cout << c;
    }
}