#include <iostream>

int n, r, c;
int res;

void    recul(int x, int y, int size)
{
    if (y == r && x == c)
    {
        std::cout << res << std::endl;
        return ;
    }
    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        recul(x, y, size / 2);
        recul(x + size / 2, y, size / 2);
        recul(x, y + size / 2, size / 2);
        recul(x + size / 2, y + size / 2, size / 2);
    }
    else
        res += size * size;
}

int main()
{
    std::cin >> n >> r >> c;
    recul(0, 0, (1 << n));
    return 0;
}