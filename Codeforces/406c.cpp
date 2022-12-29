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
int n, m, from[MAX_N], to[MAX_N], tkhor[MAX_N], tvor[MAX_N], d[MAX_N];
vector<int> adj[MAX_N], khor[MAX_N], vor[MAX_N], fard, efkhor[MAX_N];
bool vis[MAX_N], avaz[MAX_N], mar[MAX_N];
int tyal(int v)
{
	vis[v] = 1;
	int ret = adj[v].size();
	for (int k : adj[v])
	{
		int u = from[k] ^ to[k] ^ v;
		if (!vis[u])
		{
			ret += tyal(u);
		}
	}
	return ret;
}
void ffar(int v)
{
	vis[v] = 1;
	if (tkhor[v] % 2 == 1)
		fard.pb(v);
	for (int k : adj[v])
	{
		int u = from[k] ^ to[k] ^ v;
		if (!vis[u])
		{
			ffar(u);
		}
	}
}
void avyal(int v, int yp = 0)
{
	mar[v] = 1;
	for (int k : adj[v])
	{
		int u = from[k] ^ to[k] ^ v;
		if (!mar[u])
		{
			avyal(u, k);
			d[v] += d[u];
		}
	}
	if (d[v] % 2 == 1)
		avaz[yp] = 1;
}
void hal(int v)
{
	fard.clear();
	ffar(v);
	memset(mar, 0, sizeof mar);
	for (int i = 0; i < fard.size(); i++)
	{
		d[fard[i]]++;
	}
	avyal(v);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		tkhor[a]++;
		from[i] = a;
		to[i] = b;
		adj[a].pb(i);
		adj[b].pb(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if ((tyal(i) / 2) % 2 == 1)
			{
				cout << "No solution" << endl;
				return 0;
			}
		}
	}
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			hal(i);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (avaz[i] == 1)
		{
			efkhor[to[i]].pb(from[i]);
		}
		else
		{
			efkhor[from[i]].pb(to[i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < efkhor[i].size(); j += 2)
		{
			cout << efkhor[i][j] << " " << i << " " << efkhor[i][j + 1] << endl;
		}
	}
}
