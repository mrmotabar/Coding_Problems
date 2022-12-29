/*mohammadreza motabar*/
// 1 ==> nist 0 ==> hast
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
int n, m, q, a[40 + 10][40 + 10], dprasmos[40 + 10][40 + 10][40 + 10][40 + 10], dp[40 + 10][40 + 10][40 + 10][40 + 10], kolmos[40 + 10][40 + 10][40 + 10][40 + 10];
string s[40 + 10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '1')
			{
				a[i][j + 1] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int x = i; x >= 1; x--)
			{
				for (int y = j; y >= 1; y--)
				{
					int moskol = 0;
					if (a[x][y] == 0 && kolmos[i][j][x + 1][y] == 0 && kolmos[i][j][x][y + 1] == 0)
					{
						moskol = 1;
					}
					else
					{
						kolmos[i][j][x][y] = 1;
					}
					dprasmos[i][j][x][y] = dprasmos[i][j][x + 1][y] + dprasmos[i][j][x][y + 1] - dprasmos[i][j][x + 1][y + 1] + moskol;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int x = i; x <= n; x++)
			{
				for (int y = j; y <= m; y++)
				{
					dp[x][y][i][j] = dp[x - 1][y][i][j] + dp[x][y - 1][i][j] - dp[x - 1][y - 1][i][j] + dprasmos[x][y][i][j];
				}
			}
		}
	}
	while (q--)
	{
		int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
		cin >> r1 >> r2 >> r3 >> r4;
		cout << dp[r3][r4][r1][r2] << endl;
	}
}
