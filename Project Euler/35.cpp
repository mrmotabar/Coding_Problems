#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans, pw[6] = {1, 10, 100, 1000, 10000, 100000};
bool aval[1000000];
bool hast(int v)
{
    int x = v, ragh = 0;
    while (x > 0)
    {
        x /= 10;
        ragh++;
    }
    x = v;
    while (1)
    {
        if (!aval[x])
        {
            return 0;
        }
        int y = x / pw[ragh - 1];
        x %= pw[ragh - 1];
        x *= 10;
        x += y;
        if (x == v)
        {
            return 1;
        }
    }
}
int32_t main()
{
    memset(aval, 1, sizeof aval);
    aval[1] = 0;
    for (int i = 2; i < 1000000; i++)
    {
        if (aval[i])
        {
            for (int j = i * i; j < 1000000; j += i)
            {
                aval[j] = 0;
            }
        }
    }
    for (int i = 2; i < 1000000; i++)
    {
        if (hast(i))
        {
            ans++;
        }
    }
    cout << ans;
}
