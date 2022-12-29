#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<pair<int, int>, bool> mp;
int l1[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int l2[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const int MAX_N = 1000 + 10;
const int INF = 1e9 + 10;
map<pair<int, int>, int> d;
pair<int, int> q[MAX_N * MAX_N];
int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, r;
		cin >> r >> a >> b;
		for (int j = a; j <= b; j++)
		{
			mp[{r, j}] = true;
		}
	}
	int h = 0, t = 0;
	d[{x1, y1}] = 0;
	q[t++] = {x1, y1};
	while (h < t)
	{
		int vx = q[h].first;
		int vy = q[h++].second;
		for (int i = 0; i < 8; i++)
		{
			if (mp.count({vx + l1[i], vy + l2[i]}))
			{
				if (mp[{vx + l1[i], vy + l2[i]}])
				{
					if (!d.count({vx + l1[i], vy + l2[i]}))
					{
						d[{vx + l1[i], vy + l2[i]}] = INF;
					}
					if (d[{vx + l1[i], vy + l2[i]}] > d[{vx, vy}] + 1)
					{
						d[{vx + l1[i], vy + l2[i]}] = d[{vx, vy}] + 1;
						q[t++] = {vx + l1[i], vy + l2[i]};
					}
				}
			}
		}
	}
	if (!mp.count({x2, y2}))
	{
		cout << -1;
		return 0;
	}
	if (!d.count({x2, y2}))
	{
		cout << -1;
		return 0;
	}
	else
	{
		cout << d[{x2, y2}];
	}
}
