#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 500, INF = 999999;
int n, m, ans;
vector<int> adj[MAX_N];
int dp[MAX_N], q[MAX_N];
int main()
{
	cin >> n >> m;
	bool ton = 0;
	for (int i = 0; i <= n; i++)
	{
		dp[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if ((a == 1 && b == n) || (a == n && b == 1))
		{
			ton = 1;
		}
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (!ton)
	{
		int h = 0, t = 0;
		dp[1] = 0;
		q[t++] = 1;
		while (h < t)
		{
			int v = q[h++];
			for (int u : adj[v])
			{
				if (dp[v] + 1 < dp[u])
				{
					dp[u] = dp[v] + 1;
					q[t++] = u;
				}
			}
		}
	}
	else
	{
		int h = 0, t = 0;
		dp[1] = 0;
		q[t++] = 1;
		while (h < t)
		{
			int v = q[h++];
			for (int i = 1; i <= n; i++)
			{
				bool x = true;
				for (int u : adj[v])
				{
					if (i == u)
					{
						x = false;
					}
				}
				if (dp[v] + 1 < dp[i] && x && i != v)
				{
					dp[i] = dp[v] + 1;
					q[t++] = i;
				}
			}
		}
	}
	if (dp[n] == INF)
	{
		cout << -1;
		return 0;
	}
	cout << max(dp[n], 1);
}
