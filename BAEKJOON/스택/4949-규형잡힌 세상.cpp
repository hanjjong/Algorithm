#include <iostream>
#include <stack>
std::stack<char> st;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string line;
    int flag = 0;

    while (1){
        std::getline(std::cin, line);
        if (line.length() == 1 && line[0] == '.')
            return 0;
        for (auto c : line){
            if (c == '[' || c == '('){
                st.push(c);
            }
            else if (c == ']') {
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else {
                    std::cout << "no" << "\n";
                    while (!st.empty())
                        st.pop();
                    break ;
                }
            }
            else if (c == ')'){
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else {
                    std::cout << "no" << "\n";
                    while (!st.empty())
                        st.pop();
                    break ;
                }
            }
            else if (c == '.')
                flag = 1;
        }
        if (flag == 1){
            if (st.size() == 0)
                std::cout << "yes" << "\n";
            else
                std::cout << "no" << "\n";
            flag = 0;
            while (!st.empty())
                st.pop();
        }
    }
}
