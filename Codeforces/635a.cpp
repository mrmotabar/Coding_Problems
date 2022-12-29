/*mohammadreza motabar*/
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define F first
#define S second
int r, c, n, k;
int a[10 + 30][10 + 30];
int dp[10 + 30][10 + 30];
int main()
{
	cin >> r >> c >> n >> k;
	int ans = 0;
	int z, x;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> z;
		a[x][z] = 1;
	}
	dp[1][1] = a[1][1];
	for (int i = 2; i <= r; i++)
	{
		dp[i][1] = dp[i - 1][1] + a[i][1];
	}
	for (int j = 2; j <= c; j++)
	{
		dp[1][j] = dp[1][j - 1] + a[1][j];
	}
	for (int i = 2; i <= r; i++)
	{
		for (int j = 2; j <= c; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			for (int p = i; p <= r; p++)
			{
				for (int o = j; o <= c; o++)
				{
					if (dp[p][o] - dp[i - 1][o] - dp[p][j - 1] + dp[i - 1][j - 1] >= k)
					{
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
}
