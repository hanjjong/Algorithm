#include <iostream>
#include <queue>


std::queue<int> q;
int N;
int main(){
    std::cin >> N;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    while (N--){
        std::string command;
        std::cin >> command;

        if (command == "push"){
            int num;
            std::cin >> num;
            q.push(num);
        }
        else if (command == "front"){
            if (q.size() == 0)
                std::cout << "-1" << "\n";
            else
                std::cout << q.front() << "\n";
        }
        else if (command == "back"){
            if (q.size() == 0)
                std::cout << "-1" << "\n";
            else
                std::cout << q.back() << "\n";
        }
        else if (command == "size")
            std::cout << q.size() << "\n";
        else if (command == "pop"){
            if (q.size() == 0)
                std::cout << "-1" << "\n";
            else{
                std::cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (command == "empty"){
            if (q.empty())
                std::cout << "1" << "\n";
            else
                std::cout << "0" << "\n";
        }
    }
}