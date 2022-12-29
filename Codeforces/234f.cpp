/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
const int INF = 99999999;
ll n, a, b, h[200 + 100], dp[200 + 10][2][40000 + 10], ps[200 + 100];
typedef pair<int, int> pii;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		in >> h[i];
		if (i == 1)
		{
			ps[1] = h[1];
		}
		else
		{
			ps[i] = h[i] + ps[i - 1];
		}
	}
	for (int i = 0; i <= n + 1; i++)
	{
		for (int k = 0; k <= 5; k++)
		{
			for (int j = 0; j <= b; j++)
			{
				dp[i][k][j] = INF;
			}
		}
	}
	if (h[1] <= a)
	{
		dp[1][0][0] = 0;
	}
	if (h[1] <= b)
	{
		dp[1][1][h[1]] = 0;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int k = 0; k <= 1; k++)
		{
			for (int j = 0; j <= ps[i] && j <= b; j++)
			{
				if (k == 0 && ps[i] - j <= a)
				{
					dp[i][k][j] = min(dp[i - 1][0][j], (dp[i - 1][1][j] + min(h[i], h[i - 1])));
				}
				else if (ps[i] - j <= a && j >= h[i])
				{
					dp[i][k][j] = min(dp[i - 1][1][j - h[i]], (dp[i - 1][0][j - h[i]] + min(h[i], h[i - 1])));
				}
				//	cout<<i<<" "<<k<<" "<<j<<"  "<<dp[i][k][j]<<endl;
			}
		}
	}
	ll c = INF;
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= ps[n] && j <= b; j++)
		{
			c = min(c, dp[n][i][j]);
		}
	}
	if (c == INF)
	{
		out << -1;
	}
	else
	{
		out << c;
	}
}
