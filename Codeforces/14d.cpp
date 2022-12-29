/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
vector<int> adj[200 + 100];
ll vis[200 + 100], vis2[200 + 100], from[200 + 100], to[200 + 100], n, ma, mar;
void dfs(ll v, ll par, ll dee)
{
	vis[v] = 1;
	if (dee > ma)
	{
		ma = dee;
		mar = v;
	}
	for (ll u : adj[v])
	{
		if (!vis[u] && u != par)
		{
			dfs(u, par, dee + 1);
		}
	}
	vis[v] = 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		from[i] = a;
		to[i] = b;
	}
	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		ma = 0;
		mar = 0;
		dfs(from[i], to[i], 0);
		dfs(mar, to[i], 0);
		ll a = ma;
		ma = 0;
		mar = 0;
		dfs(to[i], from[i], 0);
		dfs(mar, from[i], 0);
		ll b = ma;
		ans = max(ans, a * b);
	}
	cout << ans;
}
