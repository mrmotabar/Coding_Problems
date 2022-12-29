/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
ll seg[4 * MAX_N], lazy[4 * MAX_N];
ll t, n, c;
void shift(ll id, ll b, ll e)
{
    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    int mid = (b + e) / 2;
    seg[id * 2] += (mid - b) * lazy[id];
    seg[id * 2 + 1] += (e - mid) * lazy[id];
    lazy[id] = 0;
}
void upd(ll id, ll b, ll e, ll l, ll r, ll val)
{
    if (e <= l || r <= b)
        return;
    if (l <= b && e <= r)
    {
        lazy[id] += val;
        seg[id] += val * (e - b);
        return;
    }
    shift(id, b, e);
    ll mid = (b + e) / 2;
    upd(id * 2, b, mid, l, r, val);
    upd(id * 2 + 1, mid, e, l, r, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
ll get(ll id, ll b, ll e, ll l, ll r)
{
    if (e <= l || r <= b)
        return 0;
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    shift(id, b, e);
    ll mid = (b + e) / 2;
    return get(id * 2, b, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        memset(seg, 0, sizeof seg);
        memset(lazy, 0, sizeof lazy);
        cin >> n >> c;
        ll a, p, q, v;
        while (c--)
        {
            cin >> a;
            if (a == 0)
            {
                cin >> p >> q >> v;
                upd(1, 1, n + 1, p, q + 1, v);
            }
            else
            {
                cin >> p >> q;
                cout << get(1, 1, n + 1, p, q + 1) << endl;
            }
        }
    }
}
