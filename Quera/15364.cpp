#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second
#define ll long long
const int MAX_N = 1e5 + 10;
int n, k, a[MAX_N], st[MAX_N], en[MAX_N];
ll dp[MAX_N][100 + 10];
vector<int> adj[MAX_N], sor;
void dfs(int v, int p = -1)
{
    st[v] = sor.size();
    sor.pb(v);
    for (int u : adj[v])
    {
        if (u != p)
        {
            dfs(u, v);
        }
    }
    en[v] = sor.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(0);
    memset(dp, -63, sizeof dp);
    dp[n][0] = 0;
    dp[n - 1][0] = 0;
    dp[n - 1][1] = a[sor[n - 1]];
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[en[sor[i]]][j - 1] + a[sor[i]]);
        }
    }
    cout << dp[0][k] << endl;
}
