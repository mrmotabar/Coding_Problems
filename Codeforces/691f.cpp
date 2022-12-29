/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 10, MAX_V = 3 * 1e6 + 10, INF = 1e9;
ll n, a[MAX_N], m, p[MAX_N], cnt[MAX_V], psh[MAX_V], dp[MAX_V], mv;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> p[i];
		mv = max(p[i], mv);
	}
	for (int i = 1; i <= mv + 10; i++)
	{
		for (int j = i; j <= mv + 10; j += i)
		{
			if (i == j / i)
			{
				dp[j] += (cnt[i] * (cnt[i] - 1));
			}
			else
			{
				dp[j] += cnt[i] * cnt[j / i];
			}
		}
	}
	for (int i = 1; i <= mv + 10; i++)
	{
		psh[i] = psh[i - 1] + dp[i];
	}
	ll y = n * (n - 1);
	for (int i = 0; i < m; i++)
	{
		cout << (y - psh[p[i] - 1]) << endl;
	}
}
