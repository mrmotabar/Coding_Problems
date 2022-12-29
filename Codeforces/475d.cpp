/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
ll n, a[MAX_N];
vector<pll> gc[MAX_N];
map<ll, ll> ans;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        gcd(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    gc[n].pb({a[n], 1});
    ans[a[n]]++;
    for (int i = n - 1; i >= 1; i--)
    {
        pll g = {a[i], 1};
        for (pll j : gc[i + 1])
        {
            ll g2 = gcd(a[i], j.first);
            if (g2 == g.first)
            {
                g.second += j.second;
            }
            else
            {
                gc[i].pb(g);
                ans[g.first] += g.second;
                g = {g2, j.second};
            }
        }
        ans[g.first] += g.second;
        gc[i].pb(g);
    }
    int q, x;
    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << ans[x] << endl;
    }
}
