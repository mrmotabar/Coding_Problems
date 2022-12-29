/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, m, a[MAX_N], cnt[MAX_N], ans[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		ans[i] = ans[i + 1];
		if (cnt[a[i]] == 0)
		{
			cnt[a[i]]++;
			ans[i]++;
		}
	}
	int x;
	while (m--)
	{
		cin >> x;
		cout << ans[x - 1] << endl;
	}
}
