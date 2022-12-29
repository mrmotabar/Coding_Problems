#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	char c[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			int t = 0;
			for (int k = i; k < i + 2; k++)
			{
				for (int g = j; g < j + 2; g++)
				{
					if (c[k][g] == 'f' || c[k][g] == 'a' || c[k][g] == 'c' || c[k][g] == 'e')
					{
						t++;
					}
				}
			}
			if (t == 4)
			{
				if (c[i][j] != c[i][j + 1] && c[i][j] != c[i + 1][j + 1] && c[i][j] != c[i + 1][j] && c[i + 1][j] != c[i][j + 1] && c[i + 1][j] != c[i + 1][j + 1] && c[i][j + 1] != c[i + 1][j + 1] && c[i + 1][j] != 'x' && c[i + 1][j + 1] != 'x' && c[i][j + 1] != 'x')
				{
					ans++;
				}
			}
		}
	}
	cout << ans;
}
