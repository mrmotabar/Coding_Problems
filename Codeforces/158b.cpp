#include <iostream>
#include <cstdio>
using namespace std;
int a[5];
int main()
{
	int n, ans = 0;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[x]++;
	}
	ans += a[4];
	ans += a[3];
	a[1] -= a[3];
	ans += a[2] / 2;
	ans += a[2] % 2;
	a[1] -= 2 * (a[2] % 2);
	if (a[1] > 0)
	{
		ans += a[1] / 4;
		if (a[1] % 4 != 0)
		{
			ans++;
		}
	}
	cout << ans;
}
