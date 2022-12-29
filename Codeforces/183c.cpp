#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 1e5 + 10;
int n, m, ans, dis[MAX_N];
vector<pair<int, int>> adj[MAX_N];
bool vis[MAX_N];
void dfs(int v)
{
    vis[v] = 1;
    for (auto u : adj[v])
    {
        if (!vis[u.F])
        {
            dis[u.F] = dis[v] + u.S;
            dfs(u.F);
        }
        else
        {
            ans = __gcd(ans, abs(dis[v] - dis[u.F] + u.S));
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb({b, 1});
        adj[b].pb({a, -1});
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (!ans)
    {
        cout << n << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
