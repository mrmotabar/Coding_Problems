#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10, MAX_L = 20 + 2;
int n, m, dp[MAX_N][MAX_L], child[MAX_N], h[MAX_N];
vector<int> adj[MAX_N];
void dfs(int v, int par)
{
	dp[v][0] = par;
	h[v] = h[par] + 1;
	child[v] = 1;
	for (int i = 1; i < MAX_L; i++)
	{
		dp[v][i] = dp[dp[v][i - 1]][i - 1];
	}
	for (int u : adj[v])
	{
		if (u != par)
		{
			dfs(u, v);
			child[v] += child[u];
		}
	}
}
int get_par(int v, int k)
{
	for (int i = 0; i < MAX_L; i++)
	{
		if ((k >> i) & 1)
		{
			v = dp[v][i];
		}
	}
	return v;
}
int lca(int v, int u)
{
	if (h[v] < h[u])
	{
		swap(v, u);
	}
	if (v == u)
	{
		return n;
	}
	if ((h[v] - h[u]) % 2 == 1)
	{
		return 0;
	}
	int vv = v, uu = u;
	v = get_par(v, h[v] - h[u]);
	if (v == u)
	{
		return child[get_par(vv, (h[vv] - h[uu]) / 2)] - child[get_par(vv, ((h[vv] - h[uu]) / 2) - 1)];
	}
	for (int i = MAX_L - 1; i >= 0; i--)
	{
		if (dp[v][i] != dp[u][i])
		{
			v = dp[v][i];
			u = dp[u][i];
		}
	}
	if (h[vv] == h[uu])
	{
		return n - child[v] - child[u];
	}
	return child[get_par(vv, (h[vv] + h[uu] - 2 * h[dp[v][0]]) / 2)] - child[get_par(vv, ((h[vv] + h[uu] - 2 * h[dp[v][0]]) / 2) - 1)];
}
int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << endl;
	}
}
