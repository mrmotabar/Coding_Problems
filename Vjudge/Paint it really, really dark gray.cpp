#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 1000 * 1000;
int n;
int c[MAX_N];
vector<int> adj[MAX_N], ans;
void dfs(int v, int last)
{
	c[v] *= -1;
	ans.push_back(v);
	for (int u : adj[v])
	{
		if (u != last)
		{
			dfs(u, v);
		}
	}
	if (last != 0)
	{
		if (c[v] == -1)
		{
			c[last] *= -1;
			c[v] *= -1;
			ans.push_back(last);
			ans.push_back(v);
		}
		c[last] *= -1;
		ans.push_back(last);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	c[1] *= -1;
	dfs(1, 0);
	if (c[1] == -1)
	{
		c[adj[1][0]] *= -1;
		c[1] *= -1;
		c[adj[1][0]] *= -1;
		ans.push_back(adj[1][0]);
		ans.push_back(1);
		ans.push_back(adj[1][0]);
	}
	for (int u : ans)
	{
		cout << u << " ";
	}
}
