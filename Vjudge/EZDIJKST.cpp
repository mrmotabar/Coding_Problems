#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 10000 * 2, MAX_M = 1000000 * 2, INF = 9999999;
int n, m;
bool s[MAX_N];
int dp[MAX_N];
vector<pair<int, int>> adj[MAX_N];
vector<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		q.clear();
		for (int i = 0; i <= n; i++)
		{
			dp[i] = INF;
			s[i] = 0;
			adj[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, w;
			cin >> a >> b >> w;
			adj[a].push_back({b, w});
		}
		int x, y;
		cin >> x >> y;
		dp[x] = 0;
		int h = 0;
		q.push_back(x);
		s[x] = 1;
		h++;
		while (h < n)
		{
			for (pair<int, int> u : adj[q[h - 1]])
			{
				if (dp[q[h - 1]] + u.second < dp[u.first] && s[u.first] == 0)
				{
					dp[u.first] = dp[q[h - 1]] + u.second;
				}
			}
			int min = 0;
			for (int i = 1; i <= n; i++)
			{
				if (dp[i] < dp[min] && s[i] == 0)
				{
					min = i;
				}
			}
			q.push_back(min);
			// cout<<min<<" ";
			s[min] = 1;
			h++;
		}
		if (dp[y] == INF)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << dp[y] << endl;
		}
	}
}
