#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int max_n = 1000000;
vector<int> adj[max_n];
int part[max_n];
int vis[max_n];
int cnt[3];
bool c = true;
int n, m;
void dfs(int v)
{
	for (int u : adj[v])
	{
		if (part[u] == 0)
		{
			part[u] = 3 - part[v];
			cnt[part[u]]++;
			dfs(u);
		}
		else if (part[u] == part[v])
		{
			c = false;
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
	for (int i = 1; i <= n; i++)
	{
		if (part[i] == 0)
		{
			part[i] = 1;
			dfs(i);
			cnt[1]++;
		}
	}
	if (c == false)
	{
		cout << -1;
		return 0;
	}
	cout << cnt[1] << endl;
	for (int i = 1; i <= n; i++)
	{
		if (part[i] == 1)
		{
			cout << i << " ";
		}
	}
	cout << endl;
	cout << cnt[2] << endl;
	for (int i = 1; i <= n; i++)
	{
		if (part[i] == 2)
		{
			cout << i << " ";
		}
	}
}
