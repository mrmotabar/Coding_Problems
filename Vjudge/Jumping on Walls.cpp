#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int max_n = 10000010;
int vis[2][max_n];
int d[2][max_n];
int n, k, ans;
void dfs(int i, int j, int water)
{
	if (water >= j)
	{
		return;
	}
	if (j >= n)
	{
		ans = 1;
		return;
	}
	vis[i][j] = 1;
	if (d[i][j - 1] != 1 && vis[i][j - 1] == 0)
	{
		dfs(i, j - 1, water + 1);
	}
	if ((d[1 - i][j + k] != 1 && vis[1 - i][j + k] == 0))
	{
		dfs(1 - i, j + k, water + 1);
	}
	if ((d[i][j + 1] != 1 && vis[i][j + 1] == 0))
	{
		dfs(i, j + 1, water + 1);
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char x;
			cin >> x;
			if (x == '-')
			{
			}
			else
			{
				d[i][j] = 1;
			}
		}
	}
	dfs(0, 0, -1);
	if (ans == 1)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
}
