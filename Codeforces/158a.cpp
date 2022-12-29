#include <iostream>
#include <cstdio>
using namespace std;
int a[3];
int main()
{
	int n;
	cin >> n;
	int s, ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == 1)
		{
			a[0]++;
		}
		else if (s == 2)
		{
			a[1]++;
		}
		else if (s == 3)
		{
			a[2]++;
		}
		else
		{
			ans++;
		}
	}
	while (a[2] != 0 && a[0] != 0)
	{
		a[2]--;
		a[0]--;
		ans++;
	}
	while (a[1] != 0 && a[1] - 2 >= 0)
	{
		a[1] -= 2;
		ans++;
	}
	while (a[1] != 0 && a[0] != 0 && a[0] - 2 >= 0)
	{
		a[1]--;
		a[0] -= 2;
		ans++;
	}
	while (a[1] != 0 && a[0] != 0)
	{
		a[1]--;
		a[0]--;
		ans++;
	}
	while (a[0] != 0 && a[0] - 4 >= 0)
	{
		a[0] -= 4;
		ans++;
	}
	for (int i = 0; i < 3; i++)
	{
		if (a[0] != 0)
		{
			ans += 1;
			a[0] = 0;
		}
		else if (a[i] != 0)
		{
			ans += a[i];
			a[i] = 0;
		}
	}
	cout << ans;
}
