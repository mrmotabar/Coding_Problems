/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
ll n, m, k;
ll dp[60 + 10][32768 + 1000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < (1 << m); i++)
	{
		if (__builtin_popcount(i) >= k)
		{
			dp[m][i] = 1;
		}
	}
	for (ll i = m + 1; i <= n; i++)
	{
		for (ll j = 0; j < (1 << m); j++)
		{
			if (__builtin_popcount(j) >= k)
			{
				dp[i][j >> 1] += dp[i - 1][j];
				dp[i][(j >> 1) + (1 << m - 1)] += dp[i - 1][j];
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < (1 << m); i++)
	{
		if (__builtin_popcount(i) >= k)
		{
			ans += dp[n][i];
		}
	}
	cout << ans;
}
