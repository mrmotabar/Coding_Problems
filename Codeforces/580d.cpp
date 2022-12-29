/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
int n, m, k;
ll a[18 + 10], dp[(1 << 18) + 10][18 + 10], inc[18 + 10][18 + 10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < k; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		x--;
		y--;
		inc[x][y] = c;
	}
	for (int i = 0; i < n; i++)
	{
		dp[(1 << i)][i] = a[i];
	}
	for (int i = 0; i < (1 << n); i++)
	{
		if (__builtin_popcount(i) > 1)
		{
			for (int j = 0; j < n; j++)
			{
				if ((i >> j) & 1)
				{
					ll bej = i ^ (1 << j);
					for (int akh = 0; akh < n; akh++)
					{
						if ((bej >> akh) & 1)
						{
							dp[i][j] = max(dp[i][j], dp[bej][akh] + a[j] + inc[akh][j]);
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		if (__builtin_popcount(i) == m)
		{
			for (int j = 0; j < n; j++)
			{
				if ((i >> j) && 1)
				{
					ans = max(ans, dp[i][j]);
				}
			}
		}
	}
	cout << ans;
}
