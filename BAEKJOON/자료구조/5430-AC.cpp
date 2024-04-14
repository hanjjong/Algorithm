#include <iostream>
#include <deque>
#include <algorithm>

std::deque<int> dq;
int N;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int num;
    std::string command;
    std::string array;

    std::cin >> N;
    while (N--){
        int flag = 0;
        int revflag = 0;
        dq.clear();
        std::cin >> command;
        std::cin >> num;
        std::cin >> array;
        array.erase(array.begin());
        array.erase(array.length() - 1);
        int prev = 0;
        int comma = array.find(',');
        std::string str;
        if (array.length() > 0){
            while(comma != std::string::npos){
                str = array.substr(prev, comma - prev);
                dq.push_back(std::stoi(str));
                prev = comma + 1;
                comma = array.find(',', prev);
            }
            dq.push_back(std::stoi(array.substr(prev, comma - prev)));
        }
        for (auto c : command){
            if (c == 'R'){
                if (revflag == 0)
                    revflag = 1;
                else if (revflag == 1)
                    revflag = 0;
            }
            else if(c == 'D'){
                if (dq.size() == 0){
                    std::cout << "error" << "\n";
                    flag = 1;
                    break;
                }
                else{
                    if (revflag == 0)
                        dq.pop_front();
                    else if (revflag == 1)
                        dq.pop_back();
                }
            }
        }
        if (revflag == 1){
            std::reverse(dq.begin(), dq.end());
        }
        if (flag == 0){
            std::cout << "[" ;
            for(int i = 0; i < dq.size(); i ++){
                std::cout << dq[i];
                if (i != dq.size() - 1){
                    std::cout << ",";
                }
            }
            std::cout << "]" << "\n";
        }
    }
}
