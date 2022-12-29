/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll INF = 9999999999999;
ll n, q, c[100000 + 100], v[100000 + 100], dp[100000 + 100], dp_col[100000];
pair<ll, ll> max1, max2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	ll a, b;
	while (q)
	{
		cin >> a >> b;
		for (int i = 0; i <= n; i++)
		{
			dp[i] = 0;
			dp_col[i] = -1 * INF;
		}
		max1 = {0, 0};
		max2 = {0, 0};
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			ll z, x;
			if (dp_col[c[i]] > -1 * INF)
			{
				z = dp_col[c[i]] + (a * v[i]);
			}
			else
			{
				z = b * v[i];
			}
			if (max1.first == c[i])
			{
				x = max2.second + (b * v[i]);
			}
			else
			{
				x = max1.second + (b * v[i]);
			}
			dp[i] = max(max(x, z), b * v[i]);
			dp_col[c[i]] = max(dp_col[c[i]], dp[i]);
			if (dp[i] > max1.second)
			{
				if (max1.first != c[i])
					max2 = {max1.first, max1.second};
				max1 = {c[i], dp[i]};
			}
			else if (dp[i] > max2.second && c[i] != max1.first)
			{
				max2 = {c[i], dp[i]};
			}
		}
		//	for(int i=1;i<=n;i++){
		//		cout<<dp[i]<<" ";
		//	}
		ll k = 0;
		cout << max(k, max1.second) << endl;
		q--;
	}
}
