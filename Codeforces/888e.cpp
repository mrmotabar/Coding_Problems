/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
ll n, m, a[MAX_N], mid, ans;
vector<ll> sum;
void bt(int ind, ll s)
{
    if (ind == mid)
    {
        sum.pb(s);
        return;
    }
    bt(ind + 1, (s + a[ind]) % m);
    bt(ind + 1, s);
}
void bt2(int ind, ll s)
{
    if (ind == n)
    {
        int in = lower_bound(sum.begin(), sum.end(), m - s - 1) - sum.begin();
        if (sum[in] > (m - s - 1) || in == sum.size())
        {
            in--;
        }
        ans = max(ans, s + sum[in]);
        return;
    }
    bt2(ind + 1, (s + a[ind]) % m);
    bt2(ind + 1, s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    mid = n / 2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bt(0, 0);
    sum.pb(0);
    sort(sum.begin(), sum.end());
    bt2(mid, 0);
    cout << ans << endl;
}
