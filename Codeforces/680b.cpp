#include <iostream>
#include <cstdio>
using namespace std;
bool c[100000 + 10];
int main()
{
	int n, a;
	cin >> n >> a;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	int ans = 0;
	if (c[a - 1] == 1)
	{
		ans++;
	}
	int s = a - 2;
	int e = a;
	while (s >= 0 && e <= n - 1)
	{
		if (c[s] == 1 && c[e] == 1)
		{
			ans += 2;
		}
		s--;
		e++;
	}
	if (s <= 0)
	{
		for (int i = e; i <= n - 1; i++)
		{
			if (c[i] == 1)
			{
				ans++;
			}
		}
	}
	if (e >= n - 1)
	{
		for (int i = s; i >= 0; i--)
		{
			if (c[i] == 1)
			{
				ans++;
			}
		}
	}
	cout << ans;
}
