#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int max_n = 1000000;
vector<int> adj[max_n];
int d[max_n] = {-1};
int n, m;
int maxm = 0;
int maxv = 0;
int vis[max_n];
void dfs(int v, int b)
{
	vis[v] = 1;
	d[v] = d[b] + 1;
	if (d[v] > maxm)
	{
		maxm = d[v];
		maxv = v;
	}
	for (int u : adj[v])
	{
		if (vis[u] == 0)
		{
			dfs(u, v);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		vis[i] = 0;
	}
	maxm = 0;
	dfs(maxv, 0);
	cout << maxm;
}
