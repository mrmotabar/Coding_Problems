/*mohammadreza motabar*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
ll n, a[3000 + 10], dp[3000 + 10][3000 + 10];
set<int> st;
vector<int> b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] -= i;
		st.insert(a[i]);
	}
	b.pb(0);
	for (int u : st)
	{
		b.pb(u);
	}
	// for(int i=1;i<b.size();i++){
	//	cout<<b[i]<<" ";
	// }
	// return 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = dp[i - 1][1] + abs(a[i] - b[1]);
		for (int j = 2; j < b.size(); j++)
		{
			dp[i][j] = min(dp[i][j - 1], abs(b[j] - a[i]) + dp[i - 1][j]);
		}
	}
	cout << dp[n][b.size() - 1];
}
