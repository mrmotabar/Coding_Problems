/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, seg[4 * MAX_N], so[MAX_N], dp[MAX_N], ans[MAX_N], x[MAX_N];
pair<pair<int, int>, int> xh[MAX_N];
void upd(int id, int b, int e, int p)
{
    if (p >= e || p < b)
        return;
    if (e - b == 1)
    {
        seg[id] = dp[b];
        return;
    }
    int mid = (e + b) / 2;
    upd(id * 2, b, mid, p);
    upd(id * 2 + 1, mid, e, p);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
        return 0;
    if (l <= b && e <= r)
        return seg[id];
    int mid = (b + e) / 2;
    return max(get(id * 2, b, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> xh[i].F.F >> xh[i].F.S;
        xh[i].S = i;
    }
    sort(xh + 1, xh + n + 1);
    for (int i = 1; i <= n; i++)
    {
        x[i] = xh[i].F.F;
    }
    dp[n] = n;
    upd(1, 1, n + 1, n);
    for (int i = n - 1; i >= 1; i--)
    {
        int l = i;
        int r = upper_bound(x + 1, x + n + 1, xh[i].F.F + xh[i].F.S - 1) - x - 1;
        // cout<<l<<"   "<<r<<"   "<<xh[i].F.F+xh[i].F.S-1<<endl;
        dp[i] = max(r, get(1, 1, n + 1, l, r + 1));
        upd(1, 1, n + 1, i);
    }
    for (int i = 1; i <= n; i++)
    {
        ans[xh[i].S] = dp[i] - i + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
