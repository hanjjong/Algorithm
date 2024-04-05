#include <iostream>
#include <stack>

// --------------------> 시간 초과 코드
// std::stack<int> s;
// int num;
// int N;
// std::list<int> ans;

// int main(){
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
//     std::cin >> N;
//     for (int i = 0; i < N; i++){
//         std::cin >> num;
//         s.push(num);
//         std::stack<int> copy;
//         copy = s;
//         copy.pop();
//         while (copy.size() != 0){
//             if (num <= copy.top()){
//                 ans.push_back(copy.size());
//                 break ;
//             }
//             else{
//                 copy.pop();
//             }
//         }
//         if (copy.size() == 0)
//             ans.push_back(0);
//     }
//     for (auto c : ans)
//         std::cout << c << " ";
// }
//-----------------------------

std::stack<std::pair<int, int> > s;
int N;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    s.push(std::make_pair(100000001, 0));
    for(int i = 1; i <= N; i++){
        int height;
        std::cin >> height;
        while (s.top().first < height)
            s.pop();
        std::cout << s.top().second << " ";
        s.push(std::make_pair(height, i));
    }
}