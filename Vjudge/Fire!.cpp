#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_N = 10000 + 10;
const int INF = 999999999;
char c[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
pair<int, int> q[MAX_N * MAX_N];
int l1[4] = {0, 0, -1, 1};
int l2[4] = {-1, 1, 0, 0};
int main()
{
	int r, n, m;
	cin >> r;
	while (r--)
	{
		cin >> n >> m;
		int min = INF;
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j <= m + 1; j++)
			{
				d[i][j] = INF;
			}
		}
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j <= m + 1; j++)
			{
				c[i][j] = 'a';
			}
		}
		int t = 0, x, y;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> c[i][j];
				if (c[i][j] == 'F')
				{
					d[i][j] = 0;
					q[t++] = {i, j};
				}
				if (c[i][j] == 'J')
				{
					x = i;
					y = j;
				}
			}
		}
		int h = 0;
		while (h < t)
		{
			int vx = q[h].first;
			int vy = q[h++].second;
			for (int i = 0; i < 4; i++)
			{
				if (c[vx + l1[i]][vy + l2[i]] != '#' && c[vx + l1[i]][vy + l2[i]] != 'a')
				{
					if (d[vx][vy] + 1 < d[vx + l1[i]][vy + l2[i]])
					{
						d[vx + l1[i]][vy + l2[i]] = d[vx][vy] + 1;
						q[t++] = {vx + l1[i], vy + l2[i]};
					}
				}
			}
		}
		if (x == n || x == 1 || y == m || y == 1)
		{
			min = 0;
		}
		h = 0;
		t = 0;
		d[x][y] = 0;
		q[t++] = {x, y};
		while (h < t)
		{
			int vx = q[h].first;
			int vy = q[h++].second;
			for (int i = 0; i < 4; i++)
			{
				if (c[vx + l1[i]][vy + l2[i]] != '#' && c[vx + l1[i]][vy + l2[i]] != 'a')
				{
					if (d[vx][vy] + 1 < d[vx + l1[i]][vy + l2[i]])
					{
						d[vx + l1[i]][vy + l2[i]] = d[vx][vy] + 1;
						q[t++] = {vx + l1[i], vy + l2[i]};
						if (vx + l1[i] == n || vy + l2[i] == m || vx + l1[i] == 1 || vy + l2[i] == 1)
						{
							if (min > d[vx + l1[i]][vy + l2[i]])
							{
								min = d[vx + l1[i]][vy + l2[i]];
							}
						}
					}
				}
			}
		}
		if (min == INF)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			cout << min + 1 << endl;
		}
	}
}
