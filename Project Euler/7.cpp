#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool pr[1000000 + 10];
int t = 0;
int main()
{
    memset(pr, 1, sizeof pr);
    pr[1] = 0;
    for (ll i = 2; i <= 1000000; i++)
    {
        if (pr[i])
        {
            for (ll j = i * i; j <= 1000000; j += i)
            {
                if (j <= 1e6)
                {
                    pr[j] = 0;
                }
            }
        }
    }
    for (int i = 2; i <= 1e6; i++)
    {
        if (pr[i])
        {
            t++;
        }
        if (t == 10001)
        {
            cout << i;
            return 0;
        }
    }
}
