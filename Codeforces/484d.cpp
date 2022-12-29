/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 100, INF = 1e9;
ll n, a[MAX_N], dp[2 + 5][MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	dp[0][0] = 0;
	dp[1][0] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1])
		{
			dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + a[i] - a[i - 1]);
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		}
		else
		{
			dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
			dp[0][i] = max(dp[1][i - 1], dp[0][i - 1] + a[i - 1] - a[i]);
		}
	}
	cout << max(dp[0][n - 1], dp[1][n - 1]);
}
