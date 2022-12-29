#include <bits/stdc++.h>
using namespace std;
int ans;
int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int g(int v)
{
    int ret = 0;
    while (v > 0)
    {
        ret += fac[v % 10];
        v /= 10;
    }
    return ret;
}
int main()
{
    for (int i = 3; i < 100000000; i++)
    {
        if (g(i) == i)
        {
            ans += i;
        }
    }
    cout << ans;
}
