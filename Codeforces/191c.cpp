/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9, maxl = 18;
int n, k, from[MAX_N], to[MAX_N], w[MAX_N];
int dp[MAX_N][maxl], dis[MAX_N];
vector<int> adj[MAX_N];
int get_par(int v, int k)
{
    for (int i = maxl - 1; i >= 0; i--)
    {
        if (k >> i & 1)
        {
            v = dp[v][i];
        }
    }
    return v;
}
void dfs(int v, int p = 0)
{
    dis[v] = dis[p] + 1;
    dp[v][0] = p;
    for (int i = 1; i < maxl; i++)
    {
        dp[v][i] = dp[dp[v][i - 1]][i - 1];
    }
    for (int u : adj[v])
    {
        if (u != p)
        {
            dfs(u, v);
        }
    }
}
int lca(int v, int u)
{
    if (dis[v] < dis[u])
        swap(v, u);
    v = get_par(v, dis[v] - dis[u]);
    if (u == v)
    {
        return v;
    }
    for (int i = maxl - 1; i >= 0; i--)
    {
        if (dp[v][i] != dp[u][i])
        {
            v = dp[v][i];
            u = dp[u][i];
        }
    }
    return dp[v][0];
}
int dfsw(int v, int p = 0)
{
    for (int u : adj[v])
    {
        if (u != p)
        {
            w[v] += dfsw(u, v);
        }
    }
    return w[v];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> from[i] >> to[i];
        adj[from[i]].pb(to[i]);
        adj[to[i]].pb(from[i]);
    }
    dfs(1);
    cin >> k;
    int a, b;
    while (k--)
    {
        cin >> a >> b;
        w[a]++;
        w[b]++;
        w[lca(a, b)] -= 2;
    }
    dfsw(1);
    for (int i = 0; i < n - 1; i++)
    {
        if (dis[from[i]] > dis[to[i]])
        {
            cout << w[from[i]] << endl;
        }
        else
        {
            cout << w[to[i]] << endl;
        }
    }
}
