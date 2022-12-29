#include <iostream>
#include <cstdio>
using namespace std;
char c[1000][1000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c[i][j];
		}
	}
	int ans = 0;
	int tc = 0;
	for (int i = 0; i < n; i++)
	{
		tc = 0;
		for (int j = 0; j < n; j++)
		{
			if (c[i][j] == 'C')
			{
				tc++;
			}
		}
		ans += tc * (tc - 1) / 2;
	}
	for (int i = 0; i < n; i++)
	{
		tc = 0;
		for (int j = 0; j < n; j++)
		{
			if (c[j][i] == 'C')
			{
				tc++;
			}
		}
		ans += tc * (tc - 1) / 2;
	}
	cout << ans;
}
