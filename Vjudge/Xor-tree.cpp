#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int max_n = 1000 * 1000 + 10;
vector<int> adj[max_n], ans;
int vis[max_n];
int s[max_n], en[max_n];
int n;
void dfs(int v, int p, int e, int o)
{
	vis[v] = 1;
	if (e && p % 2 == 0)
	{
		s[v] = 1 - s[v];
	}
	if (o && p % 2 == 1)
	{
		s[v] = 1 - s[v];
	}
	if (s[v] != en[v])
	{
		ans.push_back(v);
		s[v] = en[v];
		if (p % 2 == 0)
		{
			e = 1 - e;
		}
		if (p % 2 == 1)
		{
			o = 1 - o;
		}
	}
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			dfs(u, p + 1, e, o);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> en[i];
	}
	dfs(1, 0, 0, 0);
	cout << ans.size() << endl;
	for (int u : ans)
	{
		cout << u << " ";
	}
}
