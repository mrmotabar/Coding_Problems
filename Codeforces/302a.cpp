#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios ::sync_with_stdio(false);
	cin.tie(0);
	int n, m, z = 0, t = 0;
	pair<int, int> b;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == -1)
		{
			z++;
		}
		else
		{
			t++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b.first >> b.second;
		int y = b.second - b.first + 1;
		if (y % 2 == 1)
		{
			cout << 0 << "\n";
		}
		else
		{
			if (z >= y / 2 && t >= y / 2)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	}
}
