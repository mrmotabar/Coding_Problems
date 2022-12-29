/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int a, b, l;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> l;
	int ans = 0;
	int t = l;
	while (t)
	{
		if (l % 2 == t % 2)
		{
			ans += a;
		}
		else
		{
			ans += b;
		}
		t--;
	}
	cout << ans;
}
