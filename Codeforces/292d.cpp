/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 500 + 10, INF = 1e9;
int n, m, k;
vector<pair<int, int>> adj[MAX_N];
bool vis[MAX_N];
void dfs(int v, int l, int r)
{
	vis[v] = 1;
	for (auto u : adj[v])
	{
		if ((u.second < l || u.second > r) && !vis[u.first])
		{
			dfs(u.first, l, r);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		adj[a].pb({b, i});
		adj[b].pb({a, i});
	}
	cin >> k;
	int l, r, ans;
	while (k--)
	{
		ans = 0;
		memset(vis, 0, sizeof vis);
		cin >> l >> r;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				ans++;
				dfs(i, l, r);
			}
		}
		cout << ans << endl;
	}
}
