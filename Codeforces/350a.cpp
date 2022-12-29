#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
	int n, m, ans;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	ans = (a[0] * 2);
	for (int i = 1; i < n; i++)
	{
		if (ans < a[i])
		{
			ans = a[i];
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (ans >= b[i])
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}
