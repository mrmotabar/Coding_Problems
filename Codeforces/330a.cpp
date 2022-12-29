#include <iostream>
#include <cstdio>
using namespace std;
char c[100][100];
int a[100][100];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		bool g = true;
		for (int j = 0; j < m; j++)
		{
			if (c[i][j] != '.')
			{
				g = false;
			}
		}
		if (g)
		{
			ans += m;
			for (int j = 0; j < m; j++)
			{
				a[i][j]++;
			}
		}
	}
	for (int j = 0; j < m; j++)
	{
		bool g = true;
		for (int i = 0; i < n; i++)
		{
			if (c[i][j] != '.')
			{
				g = false;
			}
		}
		if (g)
		{
			ans += n;
			for (int i = 0; i < n; i++)
			{
				a[i][j]++;
			}
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > 1)
			{
				k++;
			}
		}
	}
	cout << ans - k;
}
