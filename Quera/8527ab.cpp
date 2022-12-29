/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 10, INF = 1e9;
ll n, a[MAX_N], mras[MAX_N], mchap[MAX_N], ans;
vector<int> sta1, sta2;
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
	sta1.pb(a[0]);
	for (int i = 1; i < n; i++)
	{
		while (sta1.size() && a[i] > sta1[sta1.size() - 1])
		{
			sta1.pop_back();
		}
		if (sta1.size() > 0)
			mchap[i] = sta1[0];
		sta1.pb(a[i]);
	}
	sta2.pb(a[n - 1]);
	for (int i = n - 2; i >= 0; i--)
	{
		while (sta2.size() && a[i] > sta2[sta2.size() - 1])
		{
			sta2.pop_back();
		}
		if (sta2.size() > 0)
			mras[i] = sta2[0];
		sta2.pb(a[i]);
	}
	for (int i = 1; i <= n - 2; i++)
	{
		if (min(mras[i], mchap[i]) - a[i] > 0)
		{
			ans += min(mras[i], mchap[i]) - a[i];
		}
	}
	cout << ans;
}
