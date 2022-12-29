#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 8000;
vector<int> adj[MAX_N];
bool vis[MAX_N], karm[MAX_N];
long long int rate[MAX_N], dp[MAX_N][2];
void dfs(int v)
{
	vis[v] = 1;
	dp[v][1] = rate[v];
	dp[v][0] = 0;
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			dfs(u);
			dp[v][1] += dp[u][0];
			dp[v][0] += max(dp[u][0], dp[u][1]);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> rate[i];
	}
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
		{
			break;
		}
		karm[a] = 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int rishe = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!karm[i])
		{
			rishe = i;
			break;
		}
	}
	adj[0].push_back(rishe);
	adj[rishe].push_back(0);
	dfs(0);
	cout << max(dp[0][0], dp[0][1]);
}
