#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n = 600851475143, ans = 0;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans = max(ans, i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n != 1)
    {
        ans = n;
    }
    cout << ans;
}
