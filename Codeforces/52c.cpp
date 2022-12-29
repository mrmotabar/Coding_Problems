/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 2e5 + 10, INF = 1e9;
ll n, a[MAX_N], m;
ll seg[4 * MAX_N], lazy[4 * MAX_N];
void shift(ll id, ll b, ll e)
{
    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    ll mid = (b + e) / 2;
    seg[id * 2] += lazy[id];
    seg[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
}
void upd(ll id, ll b, ll e, ll l, ll r, ll val)
{
    if (e <= l || r <= b)
        return;
    if (l <= b && e <= r)
    {
        lazy[id] += val;
        seg[id] = seg[id] + val;
        return;
    }
    shift(id, b, e);
    ll mid = (b + e) / 2;
    upd(id * 2, b, mid, l, r, val);
    upd(id * 2 + 1, mid, e, l, r, val);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
ll get(ll id, ll b, ll e, ll l, ll r)
{
    if (e <= l || r <= b)
        return INF * 10000;
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    shift(id, b, e);
    ll mid = (b + e) / 2;
    return min(get(id * 2, b, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        upd(1, 1, n + 1, i, i + 1, a[i]);
    }
    scanf("%lld", &m);
    int z, x, y;
    while (m--)
    {
        scanf("%lld %lld", &z, &x);
        z++;
        x++;
        bool type = (getchar() == ' ');
        if (type)
        {
            scanf("%lld", &y);
            if (z <= x)
            {
                upd(1, 1, n + 1, z, x + 1, y);
            }
            else
            {
                upd(1, 1, n + 1, 1, x + 1, y);
                upd(1, 1, n + 1, z, n + 1, y);
            }
        }
        else
        {
            if (z <= x)
            {
                printf("%lld\n", get(1, 1, n + 1, z, x + 1));
            }
            else
            {
                printf("%lld\n", min(get(1, 1, n + 1, 1, x + 1), get(1, 1, n + 1, z, n + 1)));
            }
        }
    }
}
