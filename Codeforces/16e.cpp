/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
double p[18 + 10][18 + 10], dp[1 << 19];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> p[i][j];
		}
	}
	dp[(1 << n) - 1] = 1;
	for (int i = (1 << n) - 2; i >= 0; i--)
	{
		int tek = __builtin_popcount(i);
		tek = tek * (tek + 1) / 2;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				for (int k = 0; k < n; k++)
				{
					if (k != j && !(i & (1 << k)))
					{
						dp[i] += (dp[(1 << k) | i] * p[j][k]) / tek;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << fixed << setprecision(6) << dp[1 << i] << " ";
	}
}
