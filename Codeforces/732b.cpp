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
int n, k, a[MAX_N], ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++)
	{
		if (a[i] + a[i - 1] < k)
		{
			ans += k - (a[i] + a[i - 1]);
			a[i] = k - a[i - 1];
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
}
