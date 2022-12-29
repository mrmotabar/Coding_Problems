#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int max_n = 1000000;
long long int n, sum, maxsum, d[max_n];
vector<pair<int, int>> adj[max_n];
int vis[max_n];
void dfs(int v)
{
	vis[v] = 1;
	maxsum = max(maxsum, d[v]);
	for (pair<int, int> u : adj[v])
	{
		if (!vis[u.first])
		{
			d[u.first] = d[v] + u.second;
			dfs(u.first);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
		sum += 2 * c;
	}
	dfs(1);
	cout << sum - maxsum;
}
