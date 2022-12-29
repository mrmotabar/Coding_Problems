#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> x;
vector<int> y;
const int MAX_N = 1000 + 20;
int n, m, sx, sy, ex, ey, ans, INF = 9999999;
pair<int, int> q[MAX_N * MAX_N];
int d[MAX_N][MAX_N];
char c[MAX_N][MAX_N];
int l1[4] = {0, 0, -1, 1};
int l2[4] = {1, -1, 0, 0};
int main()
{
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			d[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			else if (c[i][j] == 'E')
			{
				ex = i;
				ey = j;
			}
			else if (c[i][j] != 'T')
			{
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	int h = 0, t = 0;
	d[ex][ey] = 0;
	q[t++] = {ex, ey};
	while (h < t)
	{
		int vx = q[h].first;
		int vy = q[h++].second;
		for (int i = 0; i < 4; i++)
		{
			if (c[vx + l1[i]][vy + l2[i]] != 'T' && vx + l1[i] > 0 && vx + l1[i] <= n && vy + l2[i] > 0 && vy + l2[i] <= m)
			{
				if (d[vx][vy] + 1 < d[vx + l1[i]][vy + l2[i]])
				{
					d[vx + l1[i]][vy + l2[i]] = d[vx][vy] + 1;
					q[t++] = {vx + l1[i], vy + l2[i]};
				}
			}
		}
	}
	for (int i = 0; i < x.size(); i++)
	{
		if (d[x[i]][y[i]] <= d[sx][sy] && c[x[i]][y[i]] != 'T' && c[x[i]][y[i]] != '0')
		{
			ans += int(c[x[i]][y[i]]) - int('0');
		}
	}
	cout << ans;
}
