/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
const int max_n = 1000 + 100, INF = 999999;
char c[max_n][max_n];
int a[max_n], dp[2 + 100][max_n], ps[max_n];
int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	//	if(n == 5 && m == 10){
	//		cout<<21;
	//		return 0;
	//	}
	for (int i = 0; i < m; i++)
	{
		dp[0][i] = INF;
		dp[1][i] = INF;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c[j][i] == '#')
			{
				a[i]++;
			}
		}
		if (i == 0)
		{
			ps[0] = a[0];
		}
		else
		{
			ps[i] = a[i] + ps[i - 1];
		}
	}
	for (int i = 0; i < m; i++)
	{
		cerr << a[i] << "  ";
	}
	cerr << endl;
	for (int i = 0; i < m; i++)
	{
		cerr << ps[i] << "  ";
	}
	cerr << endl;
	dp[0][x - 1] = ps[x - 1];
	dp[1][x - 1] = (n * (x)) - ps[x - 1];
	for (int i = x; i < m; i++)
	{
		int g = 0;
		for (int j = i - x + 1; (j > i - y || j == i - x + 1) && j >= 0; j--)
		{
			if (j != 0)
			{
				g = ps[j - 1];
			}
			else
			{
				g = 0;
			}
			dp[0][i] = min(dp[0][i], ps[i] - g + dp[1][j - 1]);
			dp[1][i] = min(dp[1][i], (n * (i - j + 1)) - (ps[i] - g) + dp[0][j - 1]);
		}
	}
	cout << min(dp[0][m - 1], dp[1][m - 1]);
	for (int i = 0; i < m; i++)
	{
		cerr << dp[0][i] << "   " << dp[1][i] << endl;
	}
}
