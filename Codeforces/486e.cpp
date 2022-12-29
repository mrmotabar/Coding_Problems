/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 100, INF = 1e14;
ll n, k, a[MAX_N], dp[MAX_N], akh[MAX_N];
ll dp2[MAX_N], akh2[MAX_N];
ll h[MAX_N], lis;
string ans;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		akh[i] = INF;
	}
	akh[0] = 0;
	for (int i = 0; i < n; i++)
	{
		k = lower_bound(akh, akh + n, a[i]) - akh - 1;
		dp[i] = k + 1;
		lis = max(lis, dp[i]);
		akh[k + 1] = min(akh[k + 1], a[i]);
	}
	fill(akh2 + n, akh2 + MAX_N, INF);
	dp2[n - 1] = 1;
	akh2[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		k = upper_bound(akh2, akh2 + n, a[i]) - akh2;
		dp2[i] = (n - k) + 1;
		akh2[k - 1] = max(akh2[k - 1], a[i]);
		// cout<<i<<"  "<<a[i]<<"  "<<dp2[i]<<"  "<<k<<" "<<akh2[k-1]<<endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (dp[i] + dp2[i] - 1 == lis)
		{
			h[dp[i]]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (dp[i] + dp2[i] - 1 == lis)
		{
			if (h[dp[i]] == 1)
			{
				ans += '3';
			}
			else
			{
				ans += '2';
			}
		}
		else
		{
			ans += '1';
		}
	}
	cout << ans;
}
