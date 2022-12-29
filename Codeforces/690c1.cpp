#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[1000];
int vis[10000];
void dfs(int v)
{
	vis[v] = 1;
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
	dfs(1);
	for (int i = 1; i < n; i++)
	{
		if (vis[i] != 1)
		{
			cout << "no";
			return 0;
		}
	}
	if (m != n - 1)
	{
		cout << "no";
		return 0;
	}
	cout << "yes";
}
