#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 1000 * 100 + 10;
int n, m, t;
bool vis[MAX_N];
vector<pair<int, int>> adj[MAX_N];
bool dfs(int v, int e, int col)
{
	vis[v] = 1;
	if (v == e)
	{
		return true;
	}
	for (pair<int, int> u : adj[v])
	{
		if (u.second == col && !vis[u.first])
		{
			if (dfs(u.first, e, col))
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int s, e, ans = 0;
		cin >> s >> e;
		for (int j = 1; j <= 100; j++)
		{
			for (int j = 0; j <= MAX_N; j++)
			{
				vis[j] = 0;
			}
			if (dfs(s, e, j))
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
}
