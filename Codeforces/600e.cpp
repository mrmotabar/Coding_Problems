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
int n, c[MAX_N], big[MAX_N], sz[MAX_N], cnt[MAX_N], maxde;
ll ans[MAX_N], sumde;
vector<int> adj[MAX_N];
void pre(int v, int p = 0)
{
	sz[v] = 1;
	for (int u : adj[v])
	{
		if (u != p)
		{
			pre(u, v);
			sz[v] += sz[u];
			if (sz[u] > sz[big[v]])
			{
				big[v] = u;
			}
		}
	}
}
void dfs2(int v, int p = 0)
{
	cnt[c[v]]++;
	if (cnt[c[v]] == maxde)
	{
		sumde += c[v];
	}
	if (cnt[c[v]] > maxde)
	{
		sumde = c[v];
		maxde = cnt[c[v]];
	}
	for (int u : adj[v])
	{
		if (u != p)
		{
			dfs2(u, v);
		}
	}
}
void dfs(int v, int p = 0)
{
	for (int u : adj[v])
	{
		if (u != p && u != big[v])
		{
			dfs(u, v);
			memset(cnt, 0, sizeof cnt);
			sumde = 0;
			maxde = 0;
		}
	}
	if (big[v] != 0)
		dfs(big[v], v);
	for (int u : adj[v])
	{
		if (u != p && u != big[v])
		{
			dfs2(u, v);
		}
	}
	cnt[c[v]]++;
	if (cnt[c[v]] == maxde)
		sumde += c[v];
	if (cnt[c[v]] > maxde)
	{
		sumde = c[v];
		maxde = cnt[c[v]];
	}
	ans[v] = sumde;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	int a, b;
	for (int i = 1; i <= n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	pre(1);
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", ans[i]);
	}
}
