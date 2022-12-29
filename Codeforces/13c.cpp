/*mohammadreza motabar*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
ll n, a[5000 + 100], b[5000 + 100], dp[2 + 10][5000 + 100];
vector<int> sa;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	sa.push_back(b[0]);
	for (int i = 1; i < n; i++)
	{
		if (b[i] != b[i - 1])
		{
			sa.push_back(b[i]);
		}
	}
	dp[0][0] = a[0] - sa[0];
	for (int i = 1; i < sa.size(); i++)
	{
		if (a[0] > sa[i])
			dp[0][i] = a[0] - sa[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < sa.size(); j++)
		{
			if (j == 0)
				dp[i % 2][0] = dp[(i - 1) % 2][0] + abs(a[i] - sa[0]);
			else
				dp[i % 2][j] = min(dp[i % 2][j - 1], abs(sa[j] - a[i]) + dp[(i - 1) % 2][j]);
		}
	}
	ll ans = pow(2, 55);
	for (int i = 0; i < sa.size(); i++)
	{
		ans = min(ans, dp[(n - 1) % 2][i]);
	}
	cout << ans;
}
