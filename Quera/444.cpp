/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 10, INF = 1e9, MOD = 1e9 + 7;
;
ll n, q, a[MAX_N], seg[4 * MAX_N];
pair<ll, ll> lazy[4 * MAX_N];
void build(ll id, ll b, ll e)
{
    if (e - b == 1)
    {
        seg[id] = a[b];
        return;
    }
    ll mid = (e + b) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
    seg[id] %= MOD;
}
void shift(ll id, ll b, ll e)
{
    ll mid = (e + b) / 2;
    lazy[id * 2].first += lazy[id].first;
    lazy[id * 2].first %= MOD;

    lazy[id * 2].second += lazy[id].second;

    lazy[id * 2 + 1].first += lazy[id].first + (lazy[id].second * (mid - b));
    lazy[id * 2 + 1].first %= MOD;

    lazy[id * 2 + 1].second += lazy[id].second;

    seg[id * 2] += (mid - b) * (lazy[id].first + (lazy[id].first + (mid - b - 1) * lazy[id].second)) / 2;
    seg[id * 2] %= MOD;
    ll x = (lazy[id].first + (lazy[id].second * (mid - b)));
    seg[id * 2 + 1] += (e - mid) * (x + (x + (lazy[id].second * (e - mid - 1)))) / 2;
    seg[id * 2 + 1] %= MOD;

    lazy[id] = {0, 0};
}
void upd(ll id, ll b, ll e, ll l, ll r)
{
    if (e <= l || b >= r)
        return;
    if (l <= b && e <= r)
    {
        lazy[id].first += b - l + 1;
        lazy[id].first %= MOD;
        lazy[id].second++;
        seg[id] += ((e - b) * (b - l + 1 + e - l)) / 2;
        seg[id] %= MOD;
        return;
    }
    shift(id, b, e);
    ll mid = (e + b) / 2;
    upd(id * 2, b, mid, l, r);
    upd(id * 2 + 1, mid, e, l, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
    seg[id] %= MOD;
}
ll get(ll id, ll b, ll e, ll l, ll r)
{
    if (e <= l || b >= r)
        return 0;
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    shift(id, b, e);
    ll mid = (e + b) / 2;
    return (get(id * 2, b, mid, l, r) + get(id * 2 + 1, mid, e, l, r)) % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n + 1);
    string t;
    ll l, r;
    while (q--)
    {
        cin >> t >> l >> r;
        if (t == "ask")
        {
            cout << get(1, 1, n + 1, l, r + 1) << endl;
        }
        else
        {
            upd(1, 1, n + 1, l, r + 1);
        }
    }
}
