/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 2e6 + 10, INF = 1e9, mod = 1e9 + 7;
ll q, fac[MAX_N];
vector<int> amel[MAX_N];
bool aval[MAX_N];
ll tavan(int v, int t)
{
    if (t == 0)
        return 1;
    ll temp = tavan(v, t / 2) % mod;
    if (t % 2 == 1)
    {
        return (v * ((temp * temp) % mod) % mod);
    }
    return (temp * temp) % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    for (int i = 2; i < MAX_N; i++)
    {
        if (!aval[i])
        {
            amel[i].pb(i);
            for (int j = 2 * i; j < MAX_N; j += i)
            {
                aval[j] = 1;
                amel[j].pb(i);
            }
        }
    }
    fac[0] = 1;
    for (int i = 1; i < MAX_N; i++)
    {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
    ll x, y;
    while (q--)
    {
        cin >> x >> y;
        ll ans = 1;
        for (int i = 0; i < amel[x].size(); i++)
        {
            ll t = 0, j = x;
            while (j % amel[x][i] == 0)
            {
                t++;
                j /= amel[x][i];
            }
            ans *= (fac[t + y - 1] * ((tavan(fac[y - 1], mod - 2) * tavan(fac[t], mod - 2)) % mod)) % mod;
            ans %= mod;
        }
        ans *= tavan(2, y - 1);
        ans %= mod;
        cout << ans << endl;
    }
}
