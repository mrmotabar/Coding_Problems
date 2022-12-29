/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int n, a[MAX_N], dp[MAX_N], ans;
vector<pair<int, int>> sta;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		while (sta.size() && a[i] > sta[sta.size() - 1].first)
		{
			dp[i] += max(1, dp[sta[sta.size() - 1].second] - dp[i]);
			sta.pop_back();
		}
		sta.pb({a[i], i});
	}
	for (int i = 0; i < n; i++)
	{
		// cout<<dp[i]<<" ";
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
