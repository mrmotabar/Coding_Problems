#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[100000];
int tvmoalfe;
int majmoalfe;
int vis[100000];
void dfs(int v)
{
	vis[v] = 1;
	tvmoalfe++;
	majmoalfe += adj[v].size();
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			dfs(u);
		}
	}
}
int main()
{
	int n, m;
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			tvmoalfe = 0;
			majmoalfe = 0;
			dfs(i);
			if (majmoalfe < tvmoalfe * 2)
			{
				ans++;
			}
		}
	}
	cout << ans;
}
