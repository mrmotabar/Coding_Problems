/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const int MAX_N = 1e5 + 3, maxl = 18;
int n, m, dis[MAX_N], par[MAX_N][maxl], ans[MAX_N], ind, saf[MAX_N], sq;
pair<int, int> qu[MAX_N];
vector<int> adj[MAX_N];
inline void dfs(int v, int p = 0)
{
	dis[v] = dis[p] + 1;
	par[v][0] = p;
	for (int i = 1; i < maxl; i++)
	{
		par[v][i] = par[par[v][i - 1]][i - 1];
	}
	for (int u : adj[v])
	{
		if (u != p)
		{
			dfs(u, v);
		}
	}
}
inline int get_par(int v, int k)
{
	for (int i = 0; i < maxl; i++)
	{
		if ((k >> i) & 1)
		{
			v = par[v][i];
		}
	}
	return v;
}
inline int lca(int v, int u)
{
	if (dis[v] < dis[u])
		swap(v, u);
	v = get_par(v, dis[v] - dis[u]);
	if (u == v)
		return v;
	for (int i = maxl - 1; i >= 0; i--)
	{
		if (par[v][i] != par[u][i])
		{
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}
inline int jav(int i)
{
	int k = i - (i % sq);
	if (i % sq == 0)
		k = i - sq;
	int v = qu[i].S;
	int ret = ans[v];
	for (int j = i - 1; j > k; j--)
	{
		if (qu[j].F == 1)
		{
			if (lca(v, qu[j].S) != v && lca(v, qu[j].S) != qu[j].S)
				ret = min(ret, dis[v] + dis[qu[j].S] - 2 * dis[lca(v, qu[j].S)]);
			else if (lca(v, qu[j].S) == v)
				ret = min(ret, dis[qu[j].S] - dis[v]);
			else
				ret = min(ret, dis[v] - dis[qu[j].S]);
		}
	}
	return ret;
}
inline void bfs()
{
	int h = 0, t = ind, x;
	while (h < t)
	{
		x = saf[h];
		h++;
		for (int u : adj[x])
		{
			if (ans[u] > ans[x] + 1)
			{
				ans[u] = ans[x] + 1;
				saf[t] = u;
				t++;
			}
		}
	}
}
int main()
{
	memset(ans, 63, sizeof ans);
	scanf("%d %d", &n, &m);
	sq = max(int(sqrt(m / 17)), 17);
	int a, b;
	for (int i = 1; i <= n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dis[0] = -1;
	dfs(1);
	for (int i = 1; i <= m + 1; i++)
	{
		if (i == 1)
		{
			qu[i].F = 1;
			qu[i].S = 1;
		}
		else
		{
			scanf("%d %d", &qu[i].F, &qu[i].S);
		}
		if (qu[i].F == 1)
		{
			saf[ind] = qu[i].S;
			ans[qu[i].S] = 0;
			ind++;
		}
		if (qu[i].F == 2)
		{
			printf("%d\n", jav(i));
		}
		if (i % sq == 0)
		{
			bfs();
		}
	}
}
