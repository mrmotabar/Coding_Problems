/*mohammadreza motabar*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
vector<pii> adj[2 * 100000 + 100];
ll dp[2 * 100000 + 100], vis[2 * 100000 + 100], n;
void dfsroot(int v)
{
	vis[v] = 1;
	for (pii u : adj[v])
	{
		if (u.second == -1 && !vis[u.first])
		{
			dp[1]++;
		}
		if (!vis[u.first])
		{
			dfsroot(u.first);
		}
	}
}
void dfs(int v)
{
	vis[v] = 1;
	for (pii u : adj[v])
	{
		if (u.second == -1)
		{
			dp[u.first] = dp[v] - 1;
		}
		else
		{
			dp[u.first] = dp[v] + 1;
		}
		if (!vis[u.first])
		{
			dfs(u.first);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back({b, 1});
		adj[b].push_back({a, -1});
	}
	dfsroot(1);
	for (int i = 0; i <= n + 10; i++)
	{
		vis[i] = 0;
	}
	dfs(1);
	int mi;
	mi = 9999999;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] < mi)
		{
			mi = dp[i];
		}
	}
	cout << mi << endl;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] == mi)
		{
			cout << i << " ";
		}
	}
}
