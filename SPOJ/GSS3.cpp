/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 50000 + 100, INF = 1e10;
struct node
{
    ll sum, suf, pref, mx;
} seg[4 * MAX_N];
ll n, m, a[MAX_N];
node merge(node a, node b)
{
    node ret = {0, 0, 0, 0};
    ret.sum = a.sum + b.sum;
    ret.pref = max(b.pref, b.sum + a.pref);
    ret.suf = max(a.suf, a.sum + b.suf);
    ret.mx = max(max(a.mx, b.mx), a.pref + b.suf);
    return ret;
}
void upd(ll id, ll b, ll e, ll p, ll val)
{
    if (e - b == 1)
    {
        // cout<<id<<"  "<<val<<endl;
        seg[id] = {val, val, val, val};
        return;
    }
    ll mid = (b + e) / 2;
    if (p < mid)
        upd(id * 2, b, mid, p, val);
    else
        upd(id * 2 + 1, mid, e, p, val);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}
node get(ll id, ll b, ll e, ll l, ll r)
{
    if (r <= b || e <= l)
        return {-INF, -INF, -INF, -INF};
    if (l <= b && e <= r)
        return seg[id];
    ll mid = (b + e) / 2;
    return merge(get(id * 2, b, mid, l, r), get(id * 2 + 1, mid, e, l, r));
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
        upd(1, 1, n + 1, i, a[i]);
        // cout<<seg[1].sum<<endl;
    }
    cin >> m;
    ll z, x, y;
    while (m--)
    {
        cin >> z >> x >> y;
        // cout<<seg[6].sum<<endl;
        if (z == 0)
        {
            upd(1, 1, n + 1, x, y);
        }
        else
        {
            node ans = get(1, 1, n + 1, x, y + 1);
            cout << ans.mx << endl;
        }
    }
}
