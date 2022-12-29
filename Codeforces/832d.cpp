/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 2e6 + 10, INF = 1e9, maxl = 20;
vector<int> adj[MAX_N];
int dp[MAX_N][maxl], dis[MAX_N];
int get_par(int v, int k)
{
	for (int i = 0; i < maxl; i++)
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
	dp[v][0] = p;
	dis[v] = dis[p] + 1;
	for (int i = 1; i < maxl; i++)
	{
		dp[v][i] = dp[dp[v][i - 1]][i - 1];
	}
	for (auto u : adj[v])
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
	{
		swap(v, u);
	}
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++)
	{
		int a;
		cin >> a;
		adj[a].pb(i);
		adj[i].pb(a);
	}
	dfs(1);
	while (q--)
	{
		int a, b, c, lc;
		cin >> a >> b >> c;
		if (a == b && b == c)
			cout << 1 << endl;
		else if (a == b)
		{
			cout << dis[a] + dis[c] - 2 * dis[lca(a, c)] + 1 << endl;
		}
		else if (b == c)
		{
			cout << dis[b] + dis[a] - 2 * dis[lca(a, b)] + 1 << endl;
		}
		else if (a == c)
		{
			cout << dis[c] + dis[b] - 2 * dis[lca(c, b)] + 1 << endl;
		}
		else
		{
			lc = lca(a, b);
			if (dis[lca(a, c)] > dis[lc])
			{
				lc = lca(a, c);
			}
			if (dis[lca(b, c)] > dis[lc])
			{
				lc = lca(b, c);
			}
			cout << max(dis[a] + dis[lc] - 2 * dis[lca(a, lc)] + 1, max(dis[b] + dis[lc] - 2 * dis[lca(b, lc)] + 1, dis[c] + dis[lc] - 2 * dis[lca(c, lc)] + 1)) << endl;
		}
	}
}
