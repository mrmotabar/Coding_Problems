/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
ll n, m, a[100 + 100][100 + 100], b[100 + 100], ps[100 + 100][100 + 100], dp[100 + 100][10000 + 100], fs[100 + 100][100 + 100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		for (int j = 1; j <= b[i]; j++)
		{
			cin >> a[i][j];
			if (j == 1)
			{
				ps[i][1] = a[i][1];
			}
			else
			{
				ps[i][j] = a[i][j] + ps[i][j - 1];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= b[i]; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				fs[i][j] = max(fs[i][j], ps[i][k] + ps[i][b[i]] - ps[i][b[i] - j + k]);
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		dp[1][i] = fs[1][i];
	}
	for (int i = 2; i <= n; i++)
	{
		dp[i][1] = max(dp[i - 1][1], fs[i][1]);
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			for (int k = 0; k <= j && k <= b[i]; k++)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + fs[i][k]);
			}
		}
	}
	cout << dp[n][m];
}
