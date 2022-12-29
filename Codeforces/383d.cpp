/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9, MOD = 1000000007;
ll n, a[MAX_N], dp[1000 + 10][20000 + 10], ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i][10000 + a[i]] = 1;
		dp[i][10000 - a[i]] = 1;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 0; j <= 20000; j++)
		{
			if (j - a[i] >= 0)
			{
				dp[i][j] += dp[i + 1][j - a[i]];
				dp[i][j] %= MOD;
			}
			if (j + a[i] <= 20000)
			{
				dp[i][j] += dp[i + 1][j + a[i]];
				dp[i][j] %= MOD;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans += dp[i][10000];
		ans %= MOD;
		// cout<<dp[i][10000]<<endl;
	}
	cout << ans << endl;
}
