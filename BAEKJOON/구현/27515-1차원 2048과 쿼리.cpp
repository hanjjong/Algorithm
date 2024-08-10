#include <iostream>
#include <vector>

int n;
std::vector<int> tmp;
std::vector<int> v;

int flag;

int is_present(){
    for (int i = 0; i < v.size(); i++){
        std::vector<int>::iterator find = std::find(v.begin(), v.end(), v[i]);
        if (*find == 0)
            continue;
        if (find == v.end())
            return 0;
        else
            return 1;
    }
    return 1;
}

void calculate(){
    while (is_present()){
        for (int i = 0; i < v.size(); i++){
            for (int j = i; j < v.size(); j++){
                if (v[i] == v[j]){
                    v[i] = 2 * v[i];
                    v[j] = 0;
                }
            }
        }
    }
    if (v.size() == 0){
        std::cout << "234234230\n";
        return ;
    }
    std::cout << "\n" << "전체";
    for(std::vector<int>::iterator it = v.begin(); it < v.end(); ++it){
        std::cout  << *it << " ";
    }
    std::cout << "\n";
    if (flag == 1){
        std::vector<int>::iterator max = std::max_element(v.begin(), v.end());
        std::cout << "max ; "<< *max << "\n";
    }
}

int main(){

    std::cin >> n;
    while(n--){
        while(!v.empty())
            v.pop_back();
        std::string input;
        std::cin >> input; 
        if (input[0] == '+'){
            tmp.push_back(atoi(input.c_str()));
            std::cout << "asdd" <<v.size() << std::endl;
            v = tmp;
            calculate();
        }
        else if (input[0] == '-'){
            tmp.erase(std::find(tmp.end(), tmp.begin(), atoi(input.c_str())));
            v = tmp;
            calculate();
        }
    }
}