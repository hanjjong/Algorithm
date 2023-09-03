#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX 100004
int N;
int M;
int command;
int num;
int cnt;
int c;
vector<int> v(MAX, 0);
map<int, int> mp;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &command, &num);
        num--;
        if (command == 1 || command == 2)
        {
            scanf("%d", &cnt);
            if (command == 1)
                v[num] |= (1 << cnt);
            else if (command == 2)
                v[num] &= ~(1 << cnt);
        }
        else if (command == 3)
        {
            v[num] <<= 1, v[num] &= ((1 << 21) - 1);
        }
        else if (command == 4)
        {
            v[num] >>= 1, v[num] &= ~1;
        }
    }
    for(int i = 0; i < N; i++){
        if(mp[v[i]]++)
            continue;
        c++;
    }
    cout << c << "\n";

}


