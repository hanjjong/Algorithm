#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// priority_queue<pair<int, int>> pq;
priority_queue<int, vector<int>, greater<int>> bag;
priority_queue<pair<int, int>> tmp;
int N, K, m, v, c, flag;
unsigned long long res;

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> m >> v;
        pq.push({m, v});
    }
    for (int i = 0; i < K; i++)
    {
        cin >> c;
        bag.push(c);
    }
    int index = 0;
    for (int i = 0; i < K; i++)
    {
        while(index < N && bag.top() >= pq.top().first)
        {
            tmp.push({pq.top().second, pq.top().first});
            pq.pop();
            index++;
        }
            bag.pop();
        if (!tmp.empty())
        {
            res += tmp.top().first;
            tmp.pop();
        }
    }
    cout << res;
}

