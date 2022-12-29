#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool pr[2000000 + 10];
ll t = 0, sum = 0;
int main()
{
    memset(pr, 1, sizeof pr);
    pr[1] = 0;
    for (ll i = 2; i <= 2000000; i++)
    {
        if (pr[i])
        {
            for (ll j = i * i; j <= 2000000; j += i)
            {
                if (j <= 2e6)
                {
                    pr[j] = 0;
                }
            }
        }
    }
    for (int i = 2; i <= 2000000; i++)
    {
        if (pr[i])
        {
            sum += i;
        }
    }
    cout << sum;
}
