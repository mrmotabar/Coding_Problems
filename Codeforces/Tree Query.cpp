/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9, MAX_L = 18;
// voridi
int n, q;
vector<pii> adj[MAX_N];
// decompose
int par[MAX_N], rootcen;
vector<int> adjcen[MAX_N];
vector<ll> zir[MAX_N];
bool mark[MAX_N];
// lca
int dp[MAX_N][MAX_L];
ll dis[MAX_N];
namespace dec
{
    int sz[MAX_N];
    void dfs(int v, int p = 0)
    {
        sz[v] = 1;
        for (pii u : adj[v])
        {
            if (!mark[u.F] && u.F != p)
            {
                dfs(u.F, v);
                sz[v] += sz[u.F];
            }
        }
    }
    int fcen(int v, int kol)
    {
        bool boo = 0;
        int par = 0;
        while (!boo)
        {
            boo = 1;
            for (pii u : adj[v])
            {
                if (!mark[u.F] && u.F != par && sz[u.F] > kol / 2)
                {
                    par = v;
                    v = u.F;
                    boo = 0;
                    break;
                }
            }
        }
        return v;
    }
    void decen(int v, int p = 0)
    {
        dfs(v);
        int cent = fcen(v, sz[v]);
        if (p == 0)
        {
            rootcen = cent;
        }
        par[cent] = p;
        adjcen[cent].pb(p);
        adjcen[p].pb(cent);
        mark[cent] = 1;
        for (pii u : adj[cent])
        {
            if (!mark[u.F])
            {
                decen(u.F, cent);
            }
        }
    }
}
namespace lca
{
    int get_par(int v, int k)
    {
        for (int i = 0; i < MAX_L; i++)
        {
            if (k >> i & 1)
            {
                v = dp[v][i];
            }
        }
        return v;
    }
    void dfs(int v, int p, int w)
    {
        dis[v] = dis[p] + w;
        dp[v][0] = p;
        for (int i = 1; i < MAX_L; i++)
        {
            dp[v][i] = dp[dp[v][i - 1]][i - 1];
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
        {
            swap(v, u);
        }
        v = get_par(v, dis[v] - dis[u]);
        if (u == v)
        {
            return v;
        }
        for (int i = MAX_L - 1; i >= 0; i--)
        {
            if (dp[v][i] != dp[u][i])
            {
                v = dp[v][i];
                u = dp[u][i];
            }
        }
        return dp[v][0];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    dec::decen(1);
    lca::dfs(1, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        int v = i;
        while (v != 0)
        {
            int fas = dis[i] + dis[v] - 2 * dis[lca::lca(i, v)];
            zir[v].pb(fas);
            v = par[v];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(zir[i].begin(), zir[i].end());
    }
}
