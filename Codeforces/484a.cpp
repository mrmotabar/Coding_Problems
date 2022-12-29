/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ll l, r, ans1, ans2;
	while (n--)
	{
		cin >> l >> r;
		ans1 = 0;
		ll i;
		for (i = 63; i >= 0; i--)
		{
			if ((((l >> i) & 1) == 1) && (((r >> i) & 1) == 1))
			{
				ans1 |= (1ll << i);
			}
			else if (((l >> i) & 1) != ((r >> i) & 1))
			{
				ans1 |= ((1ll << i) - 1);
			}
		}
		if (__builtin_popcountll(ans1) < __builtin_popcountll(r))
		{
			ans1 = r;
		}
		cout << ans1 << endl;
	}
}
