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
bool ans[MAX_N];
int h = 0;
void dfs(int v, int de, int par)
{
	depth[v] = de;
	vis[v] = 1;
	int ch = 0;
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
			ch++;
			dfs(b, de + 1, y);
			dp[v] = min(dp[v], dp[b]);
			if (dp[b] >= depth[v])
			{
				ans[v] = 1;
			}
		}
	}
	/*if(ans[v]==1 && par!=-1 && adj[v].size()>1){
		ans[v]=1;
	}
	else{
		ans[v]=0;
	}*/
	if (ch < 2 && par == -1)
		ans[v] = false;
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
	for (int i = 0; i < n; i++)
	{
		if (ans[i])
		{
			cout << i << endl;
		}
	}
}
