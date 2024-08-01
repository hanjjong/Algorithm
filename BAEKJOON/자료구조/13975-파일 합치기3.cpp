#include <iostream>
#include <queue>
using namespace std;

long long T, K, num, res;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> K;
        res = 0;
        while(!pq.empty())
	        pq.pop();
        for (int j = 0; j < K; j++)
        {
            cin >> num;
            pq.push(num);
        }
        while (pq.size() != 1)
        {
            long long n1 = pq.top();
            pq.pop();
            long long n2 = pq.top();
            pq.pop();
            res += n1 + n2;
            pq.push(n1 + n2);
        }
        // res += pq.top();
        cout << res << "\n";
    }
}