#include <iostream>
#include <cstdio>
using namespace std;
const int max_n = 10000 + 20;
int a[max_n];
int b[max_n];
int dp[max_n][max_n];
int t = 0;
int temp_sp, n;
int path(int i, int j)
{
	if (t == dp[temp_sp - 1][n])
	{
		return 0;
	}
	if (dp[i][j] == (dp[i - 1][j] + dp[i][j - b[i + 1]]) && j - b[i + 1] > 0)
	{
		path(i - 1, j);
		path(i, j - b[i + 1]);
		cout << b[i + 1];
		t++;
	}
	else if (dp[i][j] == dp[i - 1][j])
	{
		path(i - 1, j);
	}
}
int main()
{
	a[0] = 1;
	a[1] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= (n / i); j++)
		{
			a[j * i] = 1;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == 0)
		{
			temp_sp++;
			if (a[temp_sp] == 0 || a[temp_sp] == 2)
			{
				a[i] = 2;
			}
		}
	}
	if (a[n] == 2)
	{
		cout << 1 << endl;
		cout << n;
		return 0;
	}
	int j = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == 2)
		{
			b[j] = i;
			j++;
		}
	}
	for (int i = 0; i < temp_sp; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 0; j <= n; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i < temp_sp; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j - b[i] >= 0)
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - b[i + 1]]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	// for(int i = 0 ;i < temp_sp ;i++){
	//	for(int j = 0; j <= n ; j++){
	//		cout<<dp[i][j]<<" ";
	//	}
	//	cout<<endl;
	// }
	cout << dp[temp_sp - 1][n];
	path(temp_sp - 1, n);
}
