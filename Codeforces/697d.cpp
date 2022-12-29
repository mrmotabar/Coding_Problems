/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n;
double ans[MAX_N], sz[MAX_N];
vector<int> adj[MAX_N];
void dfs(int v)
{
    sz[v] = 1;
    for (int u : adj[v])
    {
        dfs(u);
        sz[v] += sz[u];
    }
}
void solve(int v, int p = 0)
{
    if (v == 1)
    {
        ans[v] = 1;
    }
    else
    {
        ans[v] = ans[p] + 1 + (sz[p] - 1 - sz[v]) / 2;
    }
    for (int u : adj[v])
    {
        solve(u, v);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    dfs(1);
    solve(1);
    for (int i = 1; i <= n; i++)
    {
        cout << fixed << setprecision(11) << ans[i] << " ";
    }
}
