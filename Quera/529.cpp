/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 3e5 + 10, INF = 1e9, maxl = 22;
int n, m;
vector<int> adj[MAX_N], sten;
int from[MAX_N], to[MAX_N], dp[MAX_N][maxl], psh[MAX_N], st[MAX_N], en[MAX_N], dis[MAX_N];
set<int> ans;
void dfs(int v, int p = 0)
{
	dis[v] = dis[p] + 1;
	sten.pb(v);
	st[v] = sten.size();
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
	en[v] = sten.size();
}
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
int lca(int v, int u)
{
	if (dis[v] < dis[u])
	{
		swap(v, u);
	}
	int kv = v;
	v = get_par(v, dis[v] - dis[u]);
	if (u == v)
	{
		int ret = get_par(kv, dis[kv] - dis[u] - 1);
		return ret;
	}
	for (int i = maxl - 1; i >= 0; i--)
	{
		if (dp[v][i] != dp[u][i])
		{
			v = dp[v][i];
			u = dp[u][i];
		}
	}
	return v;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	m -= (n - 1);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		from[i] = a;
		to[i] = b;
	}
	dfs(1);
	for (int i = 1; i <= m; i++)
	{
		if (dis[from[i]] > dis[to[i]])
			swap(from[i], to[i]);
		int y = lca(from[i], to[i]);
		int x = dp[y][0];
		if (x == from[i])
		{
			psh[st[y]] += 1;
			psh[st[to[i]]] -= 1;
			psh[en[to[i]] + 1] += 1;
			psh[en[y] + 1] -= 1;
		}
		else
		{
			psh[st[1]] += 1;
			psh[st[from[i]]] -= 1;
			psh[en[from[i]] + 1] += 1;
			psh[st[to[i]]] -= 1;
			psh[en[to[i]] + 1] += 1;
			psh[en[1] + 1] -= 1;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		psh[i] = psh[i - 1] + psh[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (psh[i] == 0)
		{
			ans.insert(sten[i - 1]);
		}
	}
	if (ans.size() == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int u : ans)
	{
		cout << u << " ";
	}
}
