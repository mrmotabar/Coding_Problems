#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += a[(n / 2)][i];
	}
	for (int i = 0; i < n; i++)
	{
		ans += a[i][(n / 2)];
	}
	for (int i = 0; i < n; i++)
	{
		ans += a[i][i];
	}
	for (int i = 0; i < n; i++)
	{
		ans += a[i][n - 1 - i];
	}
	cout << ans - 3 * a[(n / 2)][(n / 2)];
}
