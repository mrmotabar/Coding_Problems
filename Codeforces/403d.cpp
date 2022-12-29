/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e3, INF = 1e9, mod = 1000000007;
ll t, dp[1000][45 * 23 + 100], en[1000 + 10][1000 + 10], fac[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	fac[0] = 1;
	for (int i = 1; i <= 70; i++)
	{
		fac[i] = (fac[i - 1] * i);
		fac[i] %= mod;
	}
	for (int i = 0; i <= 1000; i++)
	{
		en[i][0] = 1;
	}
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			en[i][j] = en[i - 1][j - 1] + en[i - 1][j];
			en[i][j] %= mod;
		}
	}
	dp[0][0] = 1;
	for (int k = 0; k <= 1000; k++)
	{
		for (int i = 50; i >= 1; i--)
		{
			for (int j = (45 * 23); j >= 0; j--)
			{
				if (j - k >= 0)
				{
					dp[i][j] += dp[i - 1][j - k];
					dp[i][j] %= mod;
				}
			}
		}
	}
	ll n, k, ans = 0, v;
	while (t--)
	{
		ans = 0;
		bool g = 1;
		cin >> n >> k;
		if (k > 50)
		{
			cout << 0 << endl;
			g = 0;
		}
		for (int i = 0; i <= (45 * 23) && g; i++)
		{
			if (n - i >= k)
			{
				v = ((en[n - i][k]) * (dp[k][i]));
				v %= mod;
				v *= fac[k];
				v %= mod;
				ans += v;
				ans %= mod;
				// cout<<ans<<" "<<i<<"  "<<en[n-i][k]<<" "<<dp[k][i]<<endl;
			}
		}
		if (g)
			cout << ans << endl;
	}
}
