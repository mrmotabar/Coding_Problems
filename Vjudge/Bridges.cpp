#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 1000 * 1000 + 100, INF = 999999;
int n, m;
int dp[MAX_N], depth[MAX_N], from[MAX_N], to[MAX_N];
bool vis[MAX_N];
vector<int> adj[MAX_N];
pair<int, int> ans[MAX_N];
int h = 0;
void dfs(int v, int de, int par)
{
	depth[v] = de;
	vis[v] = 1;
	for (int y : adj[v])
	{
		int b = from[y] ^ to[y] ^ v;
		if (y == par)
		{
			continue;
		}
		if (vis[b])
		{
			dp[v] = min(dp[v], depth[b]);
		}
		else
		{
			dfs(b, de + 1, y);
			dp[v] = min(dp[b], dp[v]);
		}
	}
	if (dp[v] >= de && par != -1)
	{
		// cout<<par+1<<endl;
		ans[h++] = {min(from[par], to[par]), max(from[par], to[par])};
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i <= n + 10; i++)
	{
		dp[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> from[i] >> to[i];
		// from[i]--;
		// to[i]--;
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
	}
	dfs(0, 0, -1);
	sort(ans, ans + h);
	for (int i = 0; i < h; i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
