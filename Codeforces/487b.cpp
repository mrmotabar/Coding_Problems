/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9, MAX_L = 18;
ll n, s, l, a[MAX_N];
ll mi[MAX_N][MAX_L], ma[MAX_N][MAX_L];
ll seg[4 * MAX_N], dp[MAX_N];
int kams(int v)
{
    int ind = v;
    ll x = INF, y = -INF;
    for (int i = MAX_L - 1; i >= 0; i--)
    {
        if (max(y, ma[ind][i]) - min(x, mi[ind][i]) <= s && ind + (1 << i) <= n + 1)
        {
            y = max(y, ma[ind][i]);
            x = min(x, mi[ind][i]);
            ind += (1 << i);
        }
    }
    return ind - 1;
}
void upd(int id, int b, int e, int p)
{
    if (p >= e || p < b)
        return;
    if (e - b == 1)
    {
        seg[id] = dp[p];
        return;
    }
    int mid = (b + e) / 2;
    upd(id * 2, b, mid, p);
    upd(id * 2 + 1, mid, e, p);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
        return INF;
    if (l <= b && e <= r)
        return seg[id];
    int mid = (b + e) / 2;
    return min(get(id * 2, b, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(mi, 63, sizeof mi);
    memset(ma, -63, sizeof ma);
    for (int i = 1; i <= n; i++)
    {
        mi[i][0] = a[i];
        ma[i][0] = a[i];
    }
    for (int i = 1; i < MAX_L; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ind = j + (1 << (i - 1));
            if (ind > n)
            {
                mi[j][i] = mi[j][i - 1];
                ma[j][i] = ma[j][i - 1];
            }
            else
            {
                mi[j][i] = min(mi[j][i - 1], mi[ind][i - 1]);
                ma[j][i] = max(ma[j][i - 1], ma[ind][i - 1]);
            }
        }
    }
    memset(seg, 63, sizeof seg);
    memset(dp, 63, sizeof dp);
    dp[n + 1] = 0;
    upd(1, 1, n + 2, n + 1);
    for (int i = n; i >= 1; i--)
    {
        int ind = kams(i);
        // cout<<ind<<endl;
        if (i + l - 1 <= ind)
        {
            dp[i] = get(1, 1, n + 2, i + l, ind + 2) + 1;
            upd(1, 1, n + 2, i);
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<endl;
    // }
    if (dp[1] > 1e5)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[1] << endl;
}
