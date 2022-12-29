/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 5000 + 100, INF = 1e17;
ll n, from[MAX_N], to[MAX_N], w[MAX_N];
ll dp[MAX_N], ted[MAX_N], magfas[MAX_N];
bool vis[MAX_N];
vector<pair<int, int>> adj[MAX_N];
ll ans = INF, mine = INF, sumfas;
void dfs(int v)
{
	vis[v] = 1;
	for (auto u : adj[v])
	{
		if (!vis[u.first])
		{
			dfs(u.first);
			dp[v] += dp[u.first] + (ted[u.first] * u.second);
			ted[v] += ted[u.first];
		}
	}
	ted[v]++;
}
ll dfs2(int v, int par, int wpar, int tkol)
{
	vis[v] = 1;
	if (par == -1)
	{
		magfas[v] = dp[v];
	}
	else
	{
		magfas[v] = magfas[par] - (wpar * ted[v]) + (wpar * (tkol - ted[v]));
	}
	mine = min(mine, magfas[v]);
	sumfas += magfas[v];
	for (auto u : adj[v])
	{
		if (!vis[u.first])
		{
			dfs2(u.first, v, u.second, tkol);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> from[i] >> to[i] >> w[i];
		adj[from[i]].pb({to[i], w[i]});
		adj[to[i]].pb({from[i], w[i]});
	}
	for (int i = 0; i < n - 1; i++)
	{
		memset(vis, 0, sizeof vis);
		memset(dp, 0, sizeof dp);
		memset(magfas, 0, sizeof magfas);
		memset(ted, 0, sizeof ted);
		vis[from[i]] = 1;
		dfs(to[i]);
		dfs(from[i]);
		memset(vis, 0, sizeof vis);
		vis[from[i]] = 1;
		sumfas = 0;
		mine = INF;
		dfs2(to[i], -1, 0, ted[to[i]]);
		ll a = mine;
		mine = INF;
		dfs2(from[i], -1, 0, ted[from[i]]);
		ll b = mine;
		ans = min(ans, sumfas / 2 + (ted[from[i]] * ted[to[i]] * w[i]) + (ted[from[i]] * a) + (ted[to[i]] * b));
	}
	cout << ans;
}
