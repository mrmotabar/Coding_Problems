/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
ll t, n, dp[MAX_N], dp2[MAX_N];
ll fib[MAX_N];
vector<int> gre;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3; i <= 90; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		// cout<<fib[i]<<" ";
	}
	while (t--)
	{
		cin >> n;
		gre.clear();
		gre.pb(0);
		for (int i = 90; i >= 1; i--)
		{
			if (n - fib[i] >= 0)
			{
				n -= fib[i];
				gre.pb(i);
			}
			if (n == 0)
			{
				break;
			}
		}
		reverse(gre.begin() + 1, gre.end());
		// for(int i=0;i<gre.size();i++){
		//	cout<<gre[i]<<" ";
		// }
		dp[0] = 1;
		dp2[0] = 0;
		for (int i = 1; i <= gre.size() - 1; i++)
		{
			dp[i] = dp[i - 1] + dp2[i - 1];
			dp2[i] = dp[i - 1] * ((gre[i] - gre[i - 1] - 1) / 2) + dp2[i - 1] * ((gre[i] - gre[i - 1]) / 2);
		}
		cout << dp[gre.size() - 1] + dp2[gre.size() - 1] << endl;
	}
}
