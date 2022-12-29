#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_N = 1e3;
long long int n;
long long int te[MAX_N], dp[MAX_N][MAX_N], ans[MAX_N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> te[i];
	}
	for (int i = n; i >= 1; i--)
	{
		for (int v = 1; v <= n; v++)
		{
			for (int u = 1; u <= n; u++)
			{
				dp[v][u] = min(dp[v][te[i]] + dp[te[i]][u], dp[v][u]);
			}
		}
		for (int v = i; v <= n; v++)
		{
			for (int u = i; u <= n; u++)
			{
				ans[i] += dp[te[v]][te[u]];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
}
