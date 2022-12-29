/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9, mod = 1000000007;
bool parmo[700 + 10][700 + 10];
ll dp[700 + 10][700 + 10][4 + 1][4 + 1];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		int a = 0;
		if (s[i] == '(')
		{
			a++;
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[j] == '(')
				{
					a++;
				}
				else
				{
					a--;
				}
				if (a == 0)
				{
					parmo[i][j] = 1;
				}
				if (a < 0)
				{
					break;
				}
			}
		}
	}
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (parmo[i][i + 1])
		{
			dp[i][i + 1][0][1] = 1;
			dp[i][i + 1][0][2] = 1;
			dp[i][i + 1][1][0] = 1;
			dp[i][i + 1][2][0] = 1;
		}
	}
	for (int i = s.size() - 3; i >= 0; i--)
	{
		for (int j = i + 2; j < s.size(); j++)
		{
			if (parmo[i][j])
			{
				for (int c1 = 0; c1 < 3; c1++)
				{
					for (int c2 = 0; c2 < 3; c2++)
					{
						if (parmo[i + 1][j - 1])
						{
							if (c1 == 0 && c2 == 1)
							{
								dp[i][j][c1][c2] = dp[i + 1][j - 1][0][0] + dp[i + 1][j - 1][0][2] + dp[i + 1][j - 1][1][0] + dp[i + 1][j - 1][1][2] + dp[i + 1][j - 1][2][0] + dp[i + 1][j - 1][2][2];
							}
							else if (c1 == 0 && c2 == 2)
							{
								dp[i][j][c1][c2] = dp[i + 1][j - 1][0][0] + dp[i + 1][j - 1][0][1] + dp[i + 1][j - 1][1][0] + dp[i + 1][j - 1][1][1] + dp[i + 1][j - 1][2][0] + dp[i + 1][j - 1][2][1];
							}
							else if (c1 == 1 && c2 == 0)
							{
								dp[i][j][c1][c2] = dp[i + 1][j - 1][0][0] + dp[i + 1][j - 1][2][0] + dp[i + 1][j - 1][0][1] + dp[i + 1][j - 1][2][1] + dp[i + 1][j - 1][0][2] + dp[i + 1][j - 1][2][2];
							}
							else if (c1 == 2 && c2 == 0)
							{
								dp[i][j][c1][c2] = dp[i + 1][j - 1][0][0] + dp[i + 1][j - 1][1][0] + dp[i + 1][j - 1][0][2] + dp[i + 1][j - 1][1][1] + dp[i + 1][j - 1][0][2] + dp[i + 1][j - 1][1][2];
							}
							dp[i][j][c1][c2] %= mod;
						}
						else
						{
							ll x;
							for (int k = i + 1; k < j; k++)
							{
								if (parmo[i][k] && parmo[k + 1][j])
								{
									if (c1 == 0 && c2 == 0)
									{
										x = dp[i][k][0][1] * dp[k + 1][j][2][0];
										x %= mod;
										x += dp[i][k][0][2] * dp[k + 1][j][1][0];
										x %= mod;
										x += dp[i][k][0][2] * dp[k + 1][j][0][0];
										x %= mod;
										x += dp[i][k][0][1] * dp[k + 1][j][0][0];
										x %= mod;
									}
									else if (c1 == 0 && c2 == 1)
									{
										x = dp[i][k][0][1] * dp[k + 1][j][0][1];
										x %= mod;
										x += dp[i][k][0][2] * dp[k + 1][j][0][1];
										x %= mod;
										x += dp[i][k][0][2] * dp[k + 1][j][1][1];
										x %= mod;
										x += dp[i][k][0][1] * dp[k + 1][j][2][1];
										x %= mod;
									}
									else if (c1 == 0 && c2 == 2)
									{
										x = dp[i][k][0][1] * dp[k + 1][j][0][2];
										x %= mod;
										x += dp[i][k][0][2] * dp[k + 1][j][0][2];
										x %= mod;
										x += dp[i][k][0][2] * dp[k + 1][j][1][2];
										x %= mod;
										x += dp[i][k][0][1] * dp[k + 1][j][2][2];
										x %= mod;
									}
									else if (c1 == 1 && c2 == 0)
									{
										x = dp[i][k][1][0] * dp[k + 1][j][0][0];
										x %= mod;
										x += dp[i][k][1][2] * dp[k + 1][j][0][0];
										x %= mod;
										x += dp[i][k][1][0] * dp[k + 1][j][1][0];
										x %= mod;
										x += dp[i][k][1][2] * dp[k + 1][j][1][0];
										x %= mod;
										x += dp[i][k][1][0] * dp[k + 1][j][2][0];
										x %= mod;
									}
									else if (c1 == 1 && c2 == 1)
									{
										x = dp[i][k][1][0] * dp[k + 1][j][0][1];
										x %= mod;
										x += dp[i][k][1][0] * dp[k + 1][j][1][1];
										x %= mod;
										x += dp[i][k][1][0] * dp[k + 1][j][2][1];
										x %= mod;
									}
									else if (c1 == 1 && c2 == 2)
									{
										x = dp[i][k][1][0] * dp[k + 1][j][0][2];
										x %= mod;
										x += dp[i][k][1][0] * dp[k + 1][j][1][2];
										x %= mod;
										x += dp[i][k][1][0] * dp[k + 1][j][2][2];
										x %= mod;
									}
									else if (c1 == 2 && c2 == 0)
									{
										x = dp[i][k][2][0] * dp[k + 1][j][1][0];
										x %= mod;
										x += dp[i][k][2][0] * dp[k + 1][j][2][0];
										x %= mod;
										x += dp[i][k][2][0] * dp[k + 1][j][0][0];
										x %= mod;
										x += dp[i][k][2][1] * dp[k + 1][j][2][0];
										x %= mod;
										x += dp[i][k][2][1] * dp[k + 1][j][0][0];
										x %= mod;
									}
									else if (c1 == 2 && c2 == 1)
									{
										x = dp[i][k][2][0] * dp[k + 1][j][0][1];
										x %= mod;
										x += dp[i][k][2][0] * dp[k + 1][j][1][1];
										x %= mod;
										x += dp[i][k][2][0] * dp[k + 1][j][2][1];
										x %= mod;
									}
									else if (c1 == 2 && c2 == 2)
									{
										x = dp[i][k][2][0] * dp[k + 1][j][0][2];
										x %= mod;
										x += dp[i][k][2][0] * dp[k + 1][j][1][2];
										x %= mod;
										x += dp[i][k][2][0] * dp[k + 1][j][2][2];
										x %= mod;
									}
									break;
								}
							}
							dp[i][j][c1][c2] = x;
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ans += dp[0][s.size() - 1][i][j];
			ans %= mod;
		}
	}
	cout << ans;
}
