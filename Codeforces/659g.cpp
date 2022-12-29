/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 100, INF = 1e9, MOD = 1000000007;
ll n, h[MAX_N], dp[MAX_N], ans[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
		h[i]--;
	}
	for (int i = 1; i <= n; i++)
	{
		if (h[i] >= h[i - 1])
		{
			ans[i] = h[i] + (h[i - 1] * ans[i - 1]);
		}
		else
		{
			ans[i] = (dp[i - 1] * h[i]) + h[i];
		}
		ans[i] %= MOD;
		if (h[i] <= h[i + 1] && i < n)
		{
			dp[i] = ans[i];
		}
		else if (i < n)
		{
			dp[i] = (h[i + 1] + (dp[i - 1] * min(h[i + 1], h[i - 1])));
		}
		dp[i] %= MOD;
	}
	for (int i = 1; i <= n; i++)
	{
		ans[n + 1] += ans[i];
		ans[n + 1] %= MOD;
		// cout<<ans[i]<<" ";
	}
	cout << ans[n + 1];
}
