/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const int MAX_N = 1e5 + 10;
map<int, vector<int>> adj[MAX_N];
map<int, int> lab[MAX_N];
map<pii, int> jav;
bool vis[MAX_N];
set<int> cols[MAX_N];
set<int> cs;
int n, m, q, a, b, c, ans, ind;
void dfs(int v, int l, int c)
{
	lab[v][c] = l;
	vis[v] = 1;
	if (adj[v].count(c) > 0)
	{
		for (int u : adj[v][c])
		{
			if (!vis[u])
			{
				dfs(u, l, c);
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		adj[a][c].pb(b);
		adj[b][c].pb(a);
		cols[c].insert(a);
		cs.insert(c);
	}
	for (auto i : cs)
	{
		memset(vis, 0, sizeof vis);
		for (auto j : cols[i])
		{
			if (!vis[j])
			{
				dfs(j, j, i);
			}
		}
	}
	scanf("%d", &q);
	while (q--)
	{
		ans = 0;
		scanf("%d %d", &a, &b);
		if (lab[a].size() > lab[b].size())
			swap(a, b);
		if (jav.count({a, b}) == 0)
		{
			for (pii u : lab[a])
			{
				if (lab[b].count(u.first) > 0)
					if (u.second == lab[b][u.first])
						ans++;
			}
			jav[{a, b}] = ans;
			printf("%d\n", ans);
		}
		else
		{
			printf("%d\n", jav[{a, b}]);
		}
	}
}
