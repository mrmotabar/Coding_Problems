/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
int a[10 + 10], dp[1000 + 10][10 + 10][10 + 10];
pair<int, pair<int, int>> dpp[1000 + 10][10 + 10][10 + 10];
void p(int x, int y, int z)
{
	if (x == 1)
	{
		cout << z << " ";
		return;
	}
	else
	{
		p(dpp[x][y][z].first, dpp[x][y][z].second.first, dpp[x][y][z].second.second);
		cout << z << " ";
	}
}
int main()
{
	string s;
	int m;
	cin >> s >> m;
	for (int i = 0; i < 10; i++)
	{
		if (s[i] == '0')
		{
			a[i + 1] = 0;
		}
		else
		{
			a[i + 1] = 1;
		}
	}
	for (int j = 1; j <= 10; j++)
	{
		if (a[j])
			dp[1][j][j] = 1;
	}
	for (int i = 2; i <= m; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			for (int q = 1; q <= 10; q++)
			{
				for (int k = j + 1; k <= 10; k++)
				{
					if (a[q] == 1 && a[k] == 1 && k != q)
					{
						if (dp[i - 1][k - j][q] == 1)
						{
							dp[i][j][k] = 1;
							dpp[i][j][k] = {i - 1, {k - j, q}};
						}
					}
				}
			}
		}
	}
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (dp[m][i][j])
			{
				cout << "YES" << endl;
				p(m, i, j);
				return 0;
			}
		}
	}
	cout << "NO";
}
