#include <iostream>
#include <vector>
#include <queue>

int N, M, start, end, res;
std::vector<int> vec[1001];
int visited[1001];

int main()
{
    std::cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        start = 0;
        end = 0;
        std::cin >> start >> end;
        vec[start - 1].push_back(end - 1);  
        vec[end - 1].push_back(start - 1);
    }
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            std::queue<int> q;
            q.push(i);
            while (q.size() != 0)
            {
                int current = q.front();
                q.pop();
                for (int j = 0; j < vec[current].size(); j++)
                {
                    if (visited[vec[current][j]] == 0)
                    {
                        visited[vec[current][j]] = 1;
                        q.push(vec[current][j]);
                    }
                }
            }
            res++;
        }
    }
    std::cout << res;
    return 0;
}