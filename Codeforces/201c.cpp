/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
ll n, a[MAX_N + 10];
ll dpl[MAX_N + 100], dpl2[MAX_N + 100], dpr[MAX_N + 100], dpr2[MAX_N + 100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i];
	}
	dpl[0] = 0;
	dpl2[0] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] >= 2)
		{
			dpl[i] = dpl[i - 1] + (a[i - 1] - (a[i - 1] % 2));
		}
		if (a[i - 1] >= 1)
		{
			dpl2[i] = max(dpl2[i - 1], dpl[i - 1]) + (a[i - 1] - 1 + (a[i - 1] % 2));
		}
	}
	dpr[n - 1] = 0;
	dpr2[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] >= 2)
		{
			dpr[i] = dpr[i + 1] + (a[i] - (a[i] % 2));
		}
		if (a[i] >= 1)
		{
			dpr2[i] = max(dpr2[i + 1], dpr[i + 1]) + (a[i] - 1 + (a[i] % 2));
		}
	}
	ll ans = 0, inan = -1;
	for (int i = 0; i < n; i++)
	{
		if (dpl[i] + dpr2[i] > ans)
		{
			ans = dpl[i] + dpr2[i];
			inan = i + 1;
		}
		if (dpl2[i] + dpr[i] > ans)
		{
			ans = dpl2[i] + dpr[i];
			inan = i + 1;
		}
		if (dpl[i] + dpr[i] > ans)
		{
			ans = dpl[i] + dpr[i];
			inan = i + 1;
		}
	}
	cout << ans;
}
