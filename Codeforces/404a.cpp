#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char c[1000][1000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c[i][j];
		}
	}
	char h, g;
	bool ans = true;
	for (int i = 1; i < n; i++)
	{
		if (c[i][i] != c[i - 1][i - 1])
		{
			ans = false;
		}
	}
	h = c[0][0];
	g = c[0][1];
	for (int i = 0; i < n; i++)
	{
		if (c[n - i - 1][i] != h)
		{
			ans = false;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && i + j != n - 1)
			{
				if (c[i][j] == h)
				{
					ans = false;
				}
				if (c[i][j] != g)
				{
					ans = false;
				}
			}
		}
	}
	if (ans)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
