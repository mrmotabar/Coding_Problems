/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 2000 + 10, INF = 2e9 + 10;
ll n, k, a[MAX_N], dp[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	ll s = 0, e = INF, mid;
	while (s < e - 1)
	{
		mid = (s + e) / 2;
		ll t = n;
		// memset(dp,0,sizeof dp);
		for (int i = 1; i <= n; i++)
		{
			dp[i] = i;
			for (int j = 1; j < i; j++)
			{
				if (abs(a[i] - a[j]) <= ((i - j) * mid))
				{
					dp[i] = min(dp[i], dp[j] + (i - j) - 1);
				}
			}
			t = min(t, dp[i] + (n - i) - 1);
		}
		if (t <= k)
		{
			e = mid;
		}
		else
		{
			s = mid;
		}
	}
	cout << e;
}
