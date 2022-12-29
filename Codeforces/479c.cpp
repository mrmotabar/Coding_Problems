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
int n, ans;
pii a[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].F >> a[i].S;
	}
	sort(a, a + n);
	ans = a[0].S;
	for (int i = 1; i < n; i++)
	{
		if (a[i].S < ans)
		{
			ans = a[i].F;
		}
		else
		{
			ans = a[i].S;
		}
	}
	cout << ans << endl;
}
