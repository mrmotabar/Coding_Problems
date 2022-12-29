/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 2e5 + 10, INF = 1e9;
int n, q, par[MAX_N], col[MAX_N], st[MAX_N], en[MAX_N];
int seg[4 * MAX_N], lazy[4 * MAX_N];
vector<int> sten, adj[MAX_N];
void dfs(int v, int p)
{
    sten.pb(v);
    st[v] = sten.size() - 1;
    for (int u : adj[v])
    {
        if (u != p)
        {
            dfs(u, v);
        }
    }
    en[v] = sten.size() - 1;
}
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id] = col[sten[b]];
        return;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void shift(int id, int b, int e)
{
    if (!lazy[id])
        return;
    lazy[id * 2] = 1 - lazy[id * 2];
    lazy[id * 2 + 1] = 1 - lazy[id * 2 + 1];
    int mid = (b + e) / 2;
    seg[id * 2] = (mid - b) - seg[id * 2];
    seg[id * 2 + 1] = (e - mid) - seg[id * 2 + 1];
    lazy[id] = 0;
}
void upd(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
        return;
    if (l <= b && e <= r)
    {
        lazy[id] = 1 - lazy[id];
        seg[id] = (e - b) - seg[id];
        return;
    }
    shift(id, b, e);
    int mid = (e + b) / 2;
    upd(id * 2, b, mid, l, r);
    upd(id * 2 + 1, mid, e, l, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
        return 0;
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    shift(id, b, e);
    int mid = (b + e) / 2;
    return get(id * 2, b, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> par[i];
        adj[i].pb(par[i]);
        adj[par[i]].pb(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
    }
    sten.pb(0);
    dfs(1, 0);
    build(1, 1, n + 1);
    cin >> q;
    string qu;
    int a;
    while (q--)
    {
        cin >> qu >> a;
        if (qu == "pow")
        {
            upd(1, 1, n + 1, st[a], en[a] + 1);
        }
        else
        {
            cout << get(1, 1, n + 1, st[a], en[a] + 1) << endl;
        }
    }
}
