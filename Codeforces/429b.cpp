/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
ll n, m, a[1000 + 100][1000 + 100], dp1[1000 + 100][1000 + 100], dp2[1000 + 100][1000 + 100], dp3[1000 + 100][1000 + 100], dp4[1000 + 100][1000 + 100];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	dp1[0][0] = a[0][0];
	for (int i = 1; i < n; i++)
	{
		dp1[i][0] = a[i][0] + dp1[i - 1][0];
	}
	for (int i = 1; i < m; i++)
	{
		dp1[0][i] = a[0][i] + dp1[0][i - 1];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			dp1[i][j] = max(dp1[i][j - 1], dp1[i - 1][j]) + a[i][j];
		}
	}
	dp2[0][m - 1] = a[0][m - 1];
	for (int i = 1; i < n; i++)
	{
		dp2[i][m - 1] = a[i][m - 1] + dp2[i - 1][m - 1];
	}
	for (int i = m - 2; i >= 0; i--)
	{
		dp2[0][i] = a[0][i] + dp2[0][i + 1];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = m - 2; j >= 0; j--)
		{
			dp2[i][j] = max(dp2[i][j + 1], dp2[i - 1][j]) + a[i][j];
		}
	}
	dp3[n - 1][0] = a[n - 1][0];
	for (int i = n - 2; i >= 0; i--)
	{
		dp3[i][0] = a[i][0] + dp3[i - 1][0];
	}
	for (int i = 0; i < m; i++)
	{
		dp3[n - 1][i] = a[n - 1][i] + dp3[n - 1][i - 1];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			dp3[i][j] = max(dp3[i][j - 1], dp3[i + 1][j]) + a[i][j];
		}
	}
	dp4[n - 1][m - 1] = a[n - 1][m - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		dp4[i][m - 1] = a[i][m - 1] + dp4[i + 1][m - 1];
	}
	for (int i = m - 2; i >= 0; i--)
	{
		dp4[n - 1][i] = a[n - 1][i] + dp4[n - 1][i + 1];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = m - 2; j >= 0; j--)
		{
			dp4[i][j] = max(dp4[i][j + 1], dp4[i + 1][j]) + a[i][j];
		}
	}
	ll ans = 0;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			ll z = (dp1[i - 1][j] + dp2[i][j + 1] + dp3[i][j - 1] + dp4[i + 1][j]);
			ll g = (dp1[i][j - 1] + dp2[i - 1][j] + dp3[i + 1][j] + dp4[i][j + 1]);
			ans = max(ans, z);
			ans = max(ans, g);
		}
	}
	cout << ans;
	// cout<<endl;
	//	for(int i = 0;i < n;i++){
	//		for(int j = 0;j < m;j++){
	//			cout<<dp4[i][j]<<" ";
	//		}
	//		cout<<endl;
	//	}
}
