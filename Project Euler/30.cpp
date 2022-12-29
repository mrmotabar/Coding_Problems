#include <bits/stdc++.h>
using namespace std;
int ans;
int cal(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += (x % 10) * (x % 10) * (x % 10) * (x % 10) * (x % 10);
        x /= 10;
    }
    return ret;
}
int main()
{
    for (int i = 2; i < 1e7; i++)
    {
        if (cal(i) == i)
        {
            ans += i;
        }
    }
    cout << ans;
}
