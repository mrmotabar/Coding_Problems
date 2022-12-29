/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int n, m, a[30 + 10], b[30 + 10], ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int l, r;
	for (int i = 0; i < n; i++)
	{
		cin >> l >> r;
		for (int j = l; j <= r; j++)
		{
			a[j] = 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r;
		for (int j = l; j <= r; j++)
		{
			b[j] = 1;
		}
	}
	for (int i = 0; i <= 30; i++)
	{
		if (a[i] == 1 && b[i] == 1)
		{
			ans++;
		}
	}
	cout << ans;
}
