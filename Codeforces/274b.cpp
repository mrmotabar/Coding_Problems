#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int max_n = 100000;
vector<int> adj[max_n];
int vis[max_n], vup[max_n], vdown[max_n], ind[max_n];
int n;
pair<long long, long long> dfs(int v)
{
	vis[v] = 1;
	long long in = 0, di = 0;
	for (int u : adj[v])
	{
		if (vis[u] == 0)
		{
			pair<long long, long long> k = dfs(u);
			in = max(in, k.first);
			di = max(di, k.second);
		}
	}
	int f = ind[v] + in - di;
	if (f >= 0)
	{
		return make_pair(in, di + f);
	}
	return make_pair(in - f, di);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> ind[i];
	}
	pair<long long, long long> a = dfs(1);
	cout << a.first + a.second;
}
