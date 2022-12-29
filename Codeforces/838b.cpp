#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define F first
#define S second
const int MAX_N = 5e5 + 10, INF = 999999999;
int n, q, from[MAX_N], to[MAX_N], w[MAX_N], be[MAX_N], st[MAX_N], en[MAX_N], dis[MAX_N], seg[4 * MAX_N], lazy[4 * MAX_N], sdis[4 * MAX_N], ldis[4 * MAX_N];
vector<pair<int, int>> adj[MAX_N];
vector<int> sten;
void dfs(int v, int p)
{
    sten.pb(v);
    st[v] = sten.size() - 1;
    for (pair<int, int> u : adj[v])
    {
        ;
        if (u.F != p)
        {
            dis[u.F] = dis[v] + u.S;
            dfs(u.F, v);
        }
    }
    en[v] = sten.size();
}
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id] = dis[sten[b]] + be[sten[b]];
        return;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
void shift(int id, int b, int e)
{
    seg[id * 2] += lazy[id];
    lazy[id * 2] += lazy[id];
    seg[id * 2 + 1] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
}
void upd(int id, int b, int e, int l, int r, int v)
{
    if (b >= r || l >= e)
    {
        return;
    }
    if (l <= b && e <= r)
    {
        seg[id] += v;
        lazy[id] += v;
        return;
    }
    shift(id, b, e);
    int mid = (b + e) / 2;
    upd(id * 2, b, mid, l, r, v);
    upd(id * 2 + 1, mid, e, l, r, v);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
    {
        return INF;
    }
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    shift(id, b, e);
    int mid = (b + e) / 2;
    return min(get(id * 2, b, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> from[i] >> to[i] >> w[i];
        adj[from[i]].pb({to[i], w[i]});
        adj[to[i]].pb({from[i], w[i]});
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> from[n - 1 + i] >> to[n - 1 + i] >> w[n - 1 + i];
        be[from[n - 1 + i]] = w[n - 1 + i];
    }
    sten.pb(0);
    dfs(1, 0);
    build(1, 1, n + 1);
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            int x = c - w[b];
            w[b] = c;
            if (b <= n - 1)
            {
                upd(1, 1, n + 1, max(st[from[b]], st[to[b]]), min(en[from[b]], en[to[b]]), x);
            }
            else
            {
                be[from[b]] = c;
                upd(1, 1, n + 1, st[from[b]], st[from[b]] + 1, x);
            }
        }
        else
        {
            if (b == c)
            {
                cout << 0 << "\n";
            }
            else if (st[b] < st[c] && en[b] >= en[c])
            {
                cout << (get(1, 1, n + 1, st[c], st[c] + 1) - be[c]) - (get(1, 1, n + 1, st[b], st[b] + 1) - be[b]) << "\n";
            }
            else
            {
                cout << (get(1, 1, n + 1, st[c], st[c] + 1) - be[c]) + get(1, 1, n + 1, st[b], en[b]) - (get(1, 1, n + 1, st[b], st[b] + 1) - be[b]) << "\n";
            }
        }
    }
}
