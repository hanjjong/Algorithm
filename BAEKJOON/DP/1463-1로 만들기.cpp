#include <iostream>
#include <vector>
#include <algorithm>

int array[1000001];
int N;

int main(void)
{
    array[0] = 0;
    array[1] = 0;
    array[2] = 1;
    array[3] = 1;
    // array[4] = 3;
    // array[5] = 2;

    std::cin >> N;
    for (int i = 4; i <= N; i++)
    {
        array[i] = array[i - 1] + 1;
        if (i%2==0)
            array[i] = std::min(array[i], array[i/2] + 1);
        if (i%3==0)
            array[i] = std::min(array[i], array[i/3] + 1);
    }
    std::cout << array[N];
}
