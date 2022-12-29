#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ans, co;
int dojob(ll x)
{
    int t = 0;
    while (x > 1)
    {
        if (x % 2 == 0)
        {
            x /= 2;
        }
        else
        {
            x = 3 * x + 1;
        }
        t++;
    }
    return t;
}
int main()
{
    for (int i = 1; i < 1000000; i++)
    {
        int now = dojob(i);
        if (now >= ans)
        {
            ans = now;
            co = i;
        }
    }
    cout << co;
}
