#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int MAX_N = 1e5 + 10, MOD = 1e9 + 7;
int n, m, vis[MAX_N], ans;
vector<pair<int, int>> adj[MAX_N];
void dfs(int v, int lab)
{
    vis[v] = lab;
    for (auto u : adj[v])
    {
        if (!vis[u.F])
        {
            if (u.S == 0)
            {
                dfs(u.F, 3 - lab);
            }
            else
            {
                dfs(u.F, lab);
            }
        }
        else
        {
            if (u.S == 0 && vis[v] == vis[u.F])
            {
                cout << 0 << endl;
                exit(0);
            }
            else if (u.S == 1 && vis[v] != vis[u.F])
            {
                cout << 0 << endl;
                exit(0);
            }
        }
    }
}
int pw(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    int t = pw(x, y / 2);
    t = t * t % MOD;
    if (y % 2 == 1)
    {
        t = t * x % MOD;
    }
    return t % MOD;
}
int32_t main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int v, u, noe;
        cin >> v >> u >> noe;
        adj[v].pb({u, noe});
        adj[u].pb({v, noe});
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 1);
            ans++;
        }
    }
    cout << pw(2, ans - 1) << endl;
}
