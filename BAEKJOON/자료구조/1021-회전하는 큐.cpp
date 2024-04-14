#include <iostream>
#include <algorithm>
#include <deque>

int N, M, num;
std::deque<int> dq;

int main(){
    std::cin >> N >> M;
    int res = 0; 
    for(int i = 1; i <= N ; i++){
        dq.push_back(i);
    }
    while(M--){
        std::cin >> num;
        int index = std::find(dq.begin(), dq.end(), num) - dq.begin();
        while (dq.front() != num){
            if (index < (int)dq.size() - index){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            res++;
        }
        dq.pop_front();
    }
    std::cout << res;
}