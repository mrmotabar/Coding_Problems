#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 1000000;
long long int n, m, moal;
vector<int> adj[MAX_N];
bool vis[MAX_N];
long long int pow(long long int x)
{
	if (x == 0)
	{
		return 1;
	}
	return 2 * pow(x - 1);
}
void dfs(long long int v)
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
	cin >> n >> m;
	for (long long int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (long long int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
			moal++;
		}
	}
	cout << pow(n - moal);
}
