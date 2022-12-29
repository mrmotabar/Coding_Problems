/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 5e5 + 10, INF = 1e9;
ll n, a[MAX_N], pre[MAX_N], suf[MAX_N], dpr[MAX_N], dpl[MAX_N], ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	if (pre[n] % 3 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = n; i >= 1; i--)
	{
		suf[i] = suf[i + 1] + a[i];
	}
	for (int i = n; i >= 1; i--)
	{
		dpl[i] = dpl[i + 1];
		if (suf[i] == suf[1] / 3)
		{
			dpl[i]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == pre[n] / 3)
		{
			ans += dpl[i + 2];
		}
	}
	cout << ans;
}
