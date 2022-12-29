#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10, sq = 1000;
int n, m, q;
char c[MAX_N][10 + 10];
pair<int, int> ans[MAX_N][10 + 10];
void upd(int x)
{
	for (int k = x; k < x + sq; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			ans[k][i] = {0, 0};
		}
	}
	for (int k = x; k < x + sq; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			if (c[k][i] == '<')
			{
				ans[k][i] = ans[k][i - 1];
			}
			else
			{
				break;
			}
		}
		for (int i = m; i >= 1; i--)
		{
			if (c[k][i] == '>')
			{
				ans[k][i] = ans[k][i + 1];
			}
			else
			{
				break;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			if (c[k][i] == '^')
			{
				if (k == x)
				{
					ans[x][i] = {x - 1, i};
				}
				else
				{
					ans[k][i] = ans[k - 1][i];
				}
				for (int j = i + 1; i <= m; j++)
				{
					if (c[k][j] == '<')
					{
						ans[k][j] = ans[k][j - 1];
					}
					else
					{
						break;
					}
				}
				for (int j = i - 1; j >= 1; j--)
				{
					if (c[k][j] == '>')
					{
						ans[k][j] = ans[k][j + 1];
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}
pair<int, int> get(int x, int y)
{
	if (ans[x][y].first != 0 && ans[x][y].second != 0 && ans[x][y].second != m + 1)
	{
		return get(ans[x][y].first, ans[x][y].second);
	}
	return ans[x][y];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		ans[0][i] = {0, i};
	}
	for (int i = 1; i <= n; i++)
	{
		ans[i][0] = {i, 0};
		ans[i][m + 1] = {i, m + 1};
	}
	for (int i = 1; i <= n; i += sq)
	{
		upd(i);
	}
	while (q--)
	{
		char no;
		int x, y;
		cin >> no;
		if (no == 'A')
		{
			cin >> x >> y;
			pair<int, int> a = get(x, y);
			if (a.first == 0 && a.second == 0)
			{
				cout << -1 << " " << -1 << endl;
			}
			else
			{
				cout << a.first << " " << a.second << endl;
			}
		}
		if (no == 'C')
		{
			cin >> x >> y >> no;
			c[x][y] = no;
			upd(((x - 1) / sq) * sq + 1);
		}
	}
}
