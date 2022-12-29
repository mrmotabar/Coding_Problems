/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll MAX_N = 2e5 + 100, INF = 1e9, maxl = 18;
ll n, m;
ll w[MAX_N], sor[MAX_N], from[MAX_N], to[MAX_N], par[MAX_N], valmst;
ll dis[MAX_N], dp[MAX_N][maxl], maxx[MAX_N][maxl];
bool mst[MAX_N];
vector<pll> adj[MAX_N];
bool cmp(int x, int y)
{
    return w[x] < w[y];
}
int get_root(int v)
{
    return (par[v] == v ? v : par[v] = get_root(par[v]));
}
void merge(int v, int u)
{
    int pv = get_root(v);
    int pu = get_root(u);
    if (pv == pu)
    {
        return;
    }
    par[pu] = pv;
}
pll get_par(int v, int k)
{
    ll u = 0;
    for (int i = 0; i < maxl; i++)
    {
        if (k >> i & 1)
        {
            u = max(u, maxx[v][i]);
            v = dp[v][i];
        }
    }
    return {v, u};
}
void dfs(int v, int p = 0, int vaz = 0)
{
    dp[v][0] = p;
    maxx[v][0] = vaz;
    dis[v] = dis[p] + 1;
    for (int i = 1; i < maxl; i++)
    {
        dp[v][i] = dp[dp[v][i - 1]][i - 1];
        maxx[v][i] = max(maxx[dp[v][i - 1]][i - 1], maxx[v][i - 1]);
    }
    for (auto u : adj[v])
    {
        if (u.F != p)
        {
            dfs(u.F, v, u.S);
        }
    }
}
int lca(int v, int u)
{
    if (dis[v] < dis[u])
        swap(v, u);
    pll x = get_par(v, dis[v] - dis[u]);
    v = x.F;
    ll mu = 0, mv = 0;
    if (u == v)
        return x.S;
    for (int i = maxl - 1; i >= 0; i--)
    {
        if (dp[v][i] != dp[u][i])
        {
            mv = max(mv, maxx[v][i]);
            v = dp[v][i];
            mu = max(mu, maxx[u][i]);
            u = dp[u][i];
        }
    }
    mv = max(mv, maxx[v][0]);
    mu = max(mu, maxx[u][0]);
    return max(x.S, max(mv, mu));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        w[i] = c;
        from[i] = a;
        to[i] = b;
    }
    for (int i = 0; i < n + 2; i++)
    {
        par[i] = i;
    }
    for (int i = 0; i < m + 2; i++)
    {
        sor[i] = i;
    }
    sort(sor, sor + m, cmp);
    for (int i = 0; i < m; i++)
    {
        if (get_root(from[sor[i]]) != get_root(to[sor[i]]))
        {
            merge(from[sor[i]], to[sor[i]]);
            mst[sor[i]] = 1;
            valmst += w[sor[i]];
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (mst[i])
        {
            adj[from[i]].pb({to[i], w[i]});
            adj[to[i]].pb({from[i], w[i]});
        }
    }
    dfs(1);
    // cout<<maxx[3][0]<<endl;
    // for(auto i:adj[1]) cout<<i.F<<endl;
    // return 0;
    for (int i = 0; i < m; i++)
    {
        if (mst[i])
            cout << valmst << endl;
        else
        {
            int x = lca(from[i], to[i]);
            cout << valmst - x + w[i] << endl;
        }
    }
}
