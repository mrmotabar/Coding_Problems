#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 5 * 1000;
vector<pair<int, int>> adj[MAX_N];
int n, ans = 999999, bei, bej;
void dfs(int v, int last, int c)
{
	bej = max(bej, c);
	for (pair<int, int> u : adj[v])
	{
		if (u.first == last)
		{
			continue;
		}
		bei += u.second;
		if (!u.second)
		{
			dfs(u.first, v, max(c - 1, 0));
		}
		else
		{
			dfs(u.first, v, c + 1);
		}
	}
}
int main()
{
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		adj[a].push_back({b, 0});
		adj[b].push_back({a, 1});
	}
	for (int i = 1; i <= n; i++)
	{
		bei = 0;
		bej = 0;
		dfs(i, 0, 0);
		ans = min(ans, bei - bej);
	}
	cout << ans;
}
