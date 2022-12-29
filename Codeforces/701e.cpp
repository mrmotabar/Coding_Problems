/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 2e5 + 10, INF = 1e9;
ll n, k, sz[MAX_N], big[MAX_N], root, ans, dis[MAX_N];
bool un[MAX_N];
vector<int> adj[MAX_N];
void dfs(int v, int par = 0)
{
	sz[v] = un[v];
	for (int u : adj[v])
	{
		if (u != par)
		{
			dfs(u, v);
			sz[v] += sz[u];
			if (sz[u] >= k)
				big[v] = u;
		}
	}
	if (big[v] == 0 && sz[v] >= k)
	{
		root = v;
	}
}
void dfs2(int v, int par = 0)
{
	dis[v] = dis[par] + 1;
	if (un[v])
		ans += dis[v];
	for (int u : adj[v])
	{
		if (u != par)
		{
			dfs2(u, v);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < 2 * k; i++)
	{
		int x;
		cin >> x;
		un[x] = 1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1);
	dis[0] = -1;
	dfs2(root);
	cout << ans << endl;
}
