#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int m2 = m, k2 = k, ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1)
		{
			m2--;
		}
		else
		{
			if (k2 <= 0)
			{
				m2--;
			}
			else
			{
				k2--;
			}
		}
	}
	int g;
	if (k2 < 0)
	{
		g += k2;
	}
	if (m2 < 0)
	{
		g += m2;
	}
	cout << -1 * g;
}
