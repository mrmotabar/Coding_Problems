/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9, MAX_L = 18;
ll n, q, a[MAX_N], gc[MAX_N][MAX_L];
map<ll, ll> ans;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        gcd(b, a % b);
}
ll binser(ll ind, ll temp)
{
    for (ll i = MAX_L - 1; i >= 0; i--)
    {
        if (gc[ind][i] % temp == 0)
        {
            ind += (1 << i) - 1;
        }
        if (ind > n)
            return n + 1;
    }
    return ind + 1;
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
    for (int i = n; i >= 1; i--)
    {
        gc[i][0] = a[i];
        for (int j = 1; j < MAX_L; j++)
        {
            ll ind = i + (1 << (j - 1));
            if (ind > n)
            {
                gc[i][j] = gc[i][j - 1];
            }
            else
            {
                gc[i][j] = gcd(gc[i][j - 1], gc[ind][j - 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ll temp = a[i], ind = i;
        while (ind <= n)
        {
            // if(i==1) cout<<temp<<"   ";
            ll last = ind;
            ind = binser(ind, temp);
            ans[temp] += ind - last;
            temp = gcd(temp, a[ind]);
        }
    }
    cin >> q;
    ll x;
    while (q--)
    {
        cin >> x;
        cout << ans[x] << endl;
    }
}
