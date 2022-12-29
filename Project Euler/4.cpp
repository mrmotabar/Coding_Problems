#include <bits/stdc++.h>
using namespace std;
bool ch(int x)
{
    int ret = 0, kom = x;
    while (kom > 0)
    {
        ret *= 10;
        ret += kom % 10;
        kom /= 10;
    }
    if (ret == x)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int ans = 0;
    for (int i = 100; i <= 999; i++)
    {
        for (int j = 100; j <= 999; j++)
        {
            int x = i * j;
            if (ch(x))
            {
                ans = max(ans, x);
            }
        }
    }
    cout << ans;
}
