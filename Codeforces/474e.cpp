/*mohammadreza motabar-*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
ll n, d, h[MAX_N], tar[MAX_N], tar2[MAX_N], so[MAX_N], dp[MAX_N], ans;
pll seg[4 * MAX_N];
ll par[MAX_N];
bool cmp(int x, int y)
{
    return h[x] < h[y];
}
void upd(int id, int b, int e, int p, int val)
{
    if (p >= e || p < b)
        return;
    if (e - b == 1)
    {
        seg[id].F = val;
        seg[id].S = tar[b];
        return;
    }
    int mid = (e + b) / 2;
    upd(id * 2, b, mid, p, val);
    upd(id * 2 + 1, mid, e, p, val);
    seg[id].F = max(seg[id * 2].F, seg[id * 2 + 1].F);
    if (seg[id].F == seg[id * 2].F)
        seg[id].S = seg[id * 2].S;
    else
        seg[id].S = seg[id * 2 + 1].S;
}
pll get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
        return {0, 0};
    if (l <= b && e <= r)
        return seg[id];
    int mid = (b + e) / 2;
    pll x = get(id * 2, b, mid, l, r);
    pll y = get(id * 2 + 1, mid, e, l, r);
    if (y.F > x.F)
        return y;
    else
        return x;
}
void pp(int x)
{
    if (dp[par[x]] == 0)
    {
        return;
    }
    cout << par[x] << " ";
    pp(par[x]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        tar[i] = i;
        cin >> h[i];
        so[i] = h[i];
    }
    sort(so + 1, so + n + 1);
    sort(tar + 1, tar + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        tar2[tar[i]] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        int r = lower_bound(so + 1, so + n + 1, h[i] + d) - so;
        int l = upper_bound(so + 1, so + n + 1, h[i] - d) - so;
        if (so[l] > h[i] - d)
            l--;
        if (so[r] >= h[i] + d)
        {
            pll x = get(1, 1, n + 1, r, n + 1);
            par[i] = x.S;
            dp[i] = x.F;
        }
        if (so[l] <= h[i] - d)
        {
            pll x = get(1, 1, n + 1, 1, l + 1);
            dp[i] = max(dp[i], x.F);
            if (dp[i] == x.F)
            {
                par[i] = x.S;
            }
        }
        dp[i] += 1;
        upd(1, 1, n + 1, tar2[i], dp[i]);
        if (dp[i] > dp[ans])
            ans = i;
    }
    cout << dp[ans] << endl;
    cout << ans << " ";
    pp(ans);
    cout << endl;
}
