/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const int INF = 999999999;
ll dp[300 + 10][300 + 10][300 + 10], a[300 + 10][300 + 10], n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= n; k++)
			{
				dp[i][j][k] = -INF;
			}
		}
	}
	dp[1][1][1] = a[1][1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (i + j + k > 3 && i + j - k >= 1 && i + j - k <= n)
				{
					dp[i][j][k] = max(dp[i - 1][j][k - 1], max(dp[i][j - 1][k - 1], max(dp[i - 1][j][k], dp[i][j - 1][k])));
					if (i == k)
					{
						dp[i][j][k] += a[i][j];
					}
					else
					{
						dp[i][j][k] += (a[i][j] + a[k][i + j - k]);
					}
				}
			}
		}
	}
	cout << dp[n][n][n];
}
