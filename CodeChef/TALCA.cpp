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
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1);
	cin >> q;
	while (q--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int v = max(dis[lca(a, b)], max(dis[lca(a, c)], dis[lca(b, c)]));
		// cout<<lca(a,b)<<" "<<lca(a,c)<<" "<<lca(b,c)<<endl;
		if (dis[lca(a, b)] == v)
		{
			cout << lca(a, b) << endl;
		}
		else if (dis[lca(a, c)] == v)
		{
			cout << lca(a, c) << endl;
		}
		else
		{
			cout << lca(b, c) << endl;
		}
	}
}
