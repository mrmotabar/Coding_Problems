/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 30 + 10, INF = 1e18;
ll n, k, ar[MAX_N], ans;
vector<ll> a, b, zara, zarb;
void zira(int ind, ll za)
{
    if (ind == a.size())
    {
        zara.pb(za);
        return;
    }
    if (INF / za >= a[ind])
    {
        zira(ind + 1, za * a[ind]);
    }
    zira(ind + 1, za);
}
void zirb(int ind, ll za)
{
    if (ind == b.size())
    {
        zarb.pb(za);
        return;
    }
    if (INF / za >= b[ind])
    {
        zirb(ind + 1, za * b[ind]);
    }
    zirb(ind + 1, za);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        if (i * 2 < n)
        {
            a.pb(ar[i]);
        }
        else
        {
            b.pb(ar[i]);
        }
    }
    zira(0, 1);
    zirb(0, 1);
    sort(zarb.begin(), zarb.end());
    for (int i = 0; i < zara.size(); i++)
    {
        ll c = k / zara[i];
        ll ind = upper_bound(zarb.begin(), zarb.end(), c) - zarb.begin();
        ans += ind;
    }
    cout << ans - 1 << endl;
}
