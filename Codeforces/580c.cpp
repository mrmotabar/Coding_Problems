#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[100001];
int vis[100001], n, k;
int a[100001];
int ans = 0;
void dfs(int v, int b)
{
	vis[v] = 1;
	if (b <= k && v != 1 && adj[v].size() == 1)
	{
		ans++;
	}
	if (b > k && v != 1)
	{
		return;
	}
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			if (a[u] == 1)
			{
				dfs(u, b + 1);
			}
			else
			{
				dfs(u, 0);
			}
		}
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int x, y;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, a[1]);
	cout << ans;
}
