#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
bool ch(ll x)
{
    if (x > 1000000000)
    {
        return 0;
    }
    int t[10];
    memset(t, 0, sizeof t);
    while (x > 0)
    {
        t[x % 10]++;
        if (t[x % 10] > 1 || x % 10 == 0)
        {
            return 0;
        }
        x /= 10;
    }
    return 1;
}
int main()
{
    for (int i = 1; i < 100000; i++)
    {
        ll t = i;
        int ind = 2;
        while (t * 10 < 1000000000)
        {
            for (int j = 10; 1; j *= 10)
            {
                if (ind * i < j)
                {
                    t *= j;
                    t += ind * i;
                    break;
                }
            }
            ind++;
        }
        if (ch(t))
        {
            ans = t;
        }
    }
    cout << ans;
}
