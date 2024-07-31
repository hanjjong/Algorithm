#include <iostream>

int a,b,c;
int main(){
    std::cin >> a >> b >> c;
    std::cout << pow(a,b,c);
}

long long pow(long long a, long long b, long long c){
    if (b == 1) return a % c;
    long long val = pow(a, b/2, c);
    val = val * val % c;
    if (b%2 == 0)return val;
    return val * a % c;
}