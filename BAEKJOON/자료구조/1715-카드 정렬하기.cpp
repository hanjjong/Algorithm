#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;
int N, num, res;
int main()
{
    cin >> N;
    while (N--)
    {
        cin >> num;
        q.push(-num);
    }
    res = 0;
    while (q.size() != 1)
    {
        int i = -q.top();
        q.pop();
        int j = -q.top();
        q.pop();
        q.push(-(i + j));
        res += (i + j);
    }
    cout << res;
}