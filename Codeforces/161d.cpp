#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 100 * 1000 + 10;
int dp[MAX_N][600];
vector<int> adj[MAX_N];
int ans = 0, n, k;
int vis[MAX_N];
void dfs(int v)
{
	vis[v] = 1;
	dp[v][0] = 1;
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			dfs(u);
			for (int j = 2; j <= k; j++)
			{
				ans += dp[v][j - 1] * dp[u][k - j];
			}
			for (int j = 1; j <= k; j++)
			{
				dp[v][j] += dp[u][j - 1];
			}
		}
	}
	ans += dp[v][k];
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout << ans;
}
