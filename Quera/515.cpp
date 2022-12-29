#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
const int MAX_N = 3e5 + 10;
int n, m, q, from[MAX_N], to[MAX_N], w[MAX_N], so[MAX_N], par[MAX_N], sz[MAX_N], ans[MAX_N];
set<pair<int, int>> st[MAX_N];
vector<int> zir[MAX_N];
bool cmp(int x, int y)
{
    return w[x] < w[y];
}
int get_root(int v)
{
    return (par[v] == 0 ? v : par[v] = get_root(par[v]));
}
void merge(int v, int u, int we)
{
    int pv = get_root(v);
    int pu = get_root(u);
    if (sz[pv] < sz[pu])
    {
        swap(pv, pu);
    }
    if (pv == pu)
    {
        return;
    }
    par[pu] = pv;
    sz[pv] += sz[pu];
    for (auto i : st[pu])
    {
        st[pv].insert(i);
    }
    while (st[pv].size())
    {
        auto x = *st[pv].begin();
        if (x.F > sz[pv])
        {
            break;
        }
        ans[x.S] = we;
        st[pv].erase(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fill(sz, sz + n + 1, 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> from[i] >> to[i] >> w[i];
        so[i] = i;
    }
    sort(so + 1, so + m + 1, cmp);
    cin >> q;
    fill(ans, ans + q + 1, -1);
    for (int i = 1; i <= q; i++)
    {
        int v, k;
        cin >> v >> k;
        if (k == 1)
        {
            ans[i] = 0;
        }
        else
        {
            st[v].insert({k, i});
        }
    }
    for (int i = 1; i <= m; i++)
    {
        merge(from[so[i]], to[so[i]], w[so[i]]);
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
    }
}
