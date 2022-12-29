#include <iostream>
#include <cstdio>
using namespace std;
int a[2][1000 * 1000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[0][i] >> a[1][i];
	}
	int min = a[1][0];
	int ans = 0;
	ans += min * a[0][0];
	for (int i = 1; i < n; i++)
	{
		if (a[1][i] >= min)
		{
			ans += min * a[0][i];
		}
		else
		{
			min = a[1][i];
			ans += min * a[0][i];
		}
	}
	cout << ans;
}
