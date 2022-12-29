#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m, t, y;
	cin >> n >> m;
	char s[n + 1][m + 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> s[i][j];
			if (s[i][j] == 'P')
			{
				t = j;
				y = i;
			}
		}
	}
	while (1)
	{
		if (t < 1 || t > m || (s[y][t] == '/' && s[y][t - 1] == '\\') || (s[y][t] == '\\' && s[y][t + 1] == '/'))
		{
			cout << -1 << endl;
			return 0;
		}
		if (y == n + 1)
		{
			cout << t << endl;
			return 0;
		}
		if (s[y][t] == '/')
		{
			t--;
		}
		else if (s[y][t] == '\\')
		{
			t++;
		}
		y++;
	}
}
