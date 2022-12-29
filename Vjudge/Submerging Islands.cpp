#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const long long int MAX_N = 1000 * 1000 + 100, INF = 9999999;
long long int n, m;
long long int dp[MAX_N], depth[MAX_N], from[MAX_N], to[MAX_N];
bool vis[MAX_N];
vector<int> adj[MAX_N];
long long int ans;
void dfs(int v, int de, int par)
{
	depth[v] = de;
	vis[v] = 1;
	dp[v] = INF;
	bool f = false;
	int ch = 0;
	for (int y : adj[v])
	{
		int b = from[y] ^ to[y] ^ v;
		if (y == par)
		{
			continue;
		}
		if (vis[b])
		{
			dp[v] = min(dp[v], depth[b]);
		}
		else
		{
			ch++;
			dfs(b, de + 1, y);
			dp[v] = min(dp[v], dp[b]);
			if (dp[b] >= depth[v])
			{
				f = true;
			}
		}
	}
	if (ch < 2 && par == -1)
		f = false;
	if (f)
	{
		ans++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}
		for (int i = 0; i <= n; i++)
		{
			vis[i] = 0;
			adj[i].clear();
		}
		ans = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> from[i] >> to[i];
			from[i]--;
			to[i]--;
			adj[from[i]].push_back(i);
			adj[to[i]].push_back(i);
		}
		dfs(0, 0, -1);
		cout << ans << endl;
	}
}
