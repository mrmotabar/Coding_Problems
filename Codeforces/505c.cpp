/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 60000 + 10, INF = 1e9;
int n, d, sq, dp[MAX_N][600 + 10], p[MAX_N], h[MAX_N], maxe;
int dfs(int i, int j)
{
	if (i > 30000 || i < d || j == 0)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	if (j > 1)
	{
		dp[i][j] = max(max(dfs(i + j, j), dfs(i + j + 1, j + 1)), dfs(i + j - 1, j - 1)) + h[i];
	}
	else
	{
		dp[i][j] = max(dfs(i + j, j), dfs(i + j + 1, j + 1)) + h[i];
	}
	return dp[i][j];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> d;
	sq = sqrt(d);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		h[p[i]]++;
	}
	memset(dp, -1, sizeof dp);
	cout << dfs(d, d);
}
