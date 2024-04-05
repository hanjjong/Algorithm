#include <iostream>
#include <list>

std::list<char> L;
std::list<char> ans;
int N;
int main(){
    std::cin >> N;
    std::string str;
    while (N--){
        std::cin >> str;
        ans.clear();
        L.clear();
        for (auto c : str)
            L.push_back(c);
        auto cursor = ans.begin();
        for (auto c : L){
            if (c == '<'){
                if (cursor != ans.begin()) cursor--; 
            } 
            else if (c == '>') {
                if (cursor != ans.end()) cursor++;
            }
            else if (c == '-') {
                if (cursor != ans.begin()){
                    cursor--;
                    cursor = ans.erase(cursor);
                }
            }
            else{
                ans.insert(cursor, c);
            }
        }
        for (auto c : ans){
            std::cout << c;
        }
        std::cout << "\n";
    }

}