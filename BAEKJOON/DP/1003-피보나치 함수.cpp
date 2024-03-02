#include <iostream>
#include <vector>

std::vector<std::pair<int, int> > arr;

int main()
{
    int count, N = 0;
    std::cin >> count;
    arr.push_back(std::make_pair(1, 0));
    arr.push_back(std::make_pair(0, 1));
    for(int i = 2; i <= 40; i++)
        arr.push_back(std::make_pair(arr[i - 1].first + arr[i - 2].first, arr[i - 1].second + arr[i - 2].second));
    for (int i = 0; i < count; i++)
    {
        std::cin >> N;
        if (N <= 40)
            std::cout << arr[N].first << " " << arr[N].second << std::endl;
    }
}