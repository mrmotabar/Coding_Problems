#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define F first;
#define S second;
const int max_n = 200010;
map<pair<int, int>, int> mp[max_n];
pair<int, int> q[max_n];
int main()
{
	int z;
	cin >> z;
	while (z--)
	{
		int A, B, C;
		bool g = true;
		cin >> A >> B >> C;
		mp[z][{0, 0}] = 0;
		int h = 0, t = 0;
		q[t].first = 0;
		q[t++].second = 0;
		while (h < t)
		{
			int x = q[h].first;
			int y = q[h++].second;
			if (x == C || y == C)
			{
				cout << mp[z][{x, y}] << endl;
				g = false;
				break;
			}
			if (!mp[z].count({0, y}))
			{
				mp[z][{0, y}] = 99999900;
			}
			if (!mp[z].count({x, 0}))
			{
				mp[z][{x, 0}] = 99999900;
			}
			if (!mp[z].count({A, y}))
			{
				mp[z][{A, y}] = 99999900;
			}
			if (!mp[z].count({x, B}))
			{
				mp[z][{x, B}] = 99999900;
			}
			if (!mp[z].count({x - min(x, B - y), y + min(x, B - y)}))
			{
				mp[z][{x - min(x, B - y), y + min(x, B - y)}] = 99999900;
			}
			if (!mp[z].count({x + min(y, A - x), y - min(y, A - x)}))
			{
				mp[z][{x + min(y, A - x), y - min(y, A - x)}] = 99999900;
			}
			if (mp[z][{x, y}] + 1 < mp[z][{0, y}])
			{
				mp[z][{0, y}] = mp[z][{x, y}] + 1;
				q[t].first = 0;
				q[t++].second = y;
			}
			if (mp[z][{x, y}] + 1 < mp[z][{x, 0}])
			{
				mp[z][{x, 0}] = mp[z][{x, y}] + 1;
				q[t].first = x;
				q[t++].second = 0;
			}
			if (mp[z][{x, y}] + 1 < mp[z][{A, y}])
			{
				mp[z][{A, y}] = mp[z][{x, y}] + 1;
				q[t].first = A;
				q[t++].second = y;
			}
			if (mp[z][{x, y}] + 1 < mp[z][{x, B}])
			{
				mp[z][{x, B}] = mp[z][{x, y}] + 1;
				q[t].first = x;
				q[t++].second = B;
			}
			if (mp[z][{x, y}] + 1 < mp[z][{x - min(x, B - y), y + min(x, B - y)}])
			{
				mp[z][{x - min(x, B - y), y + min(x, B - y)}] = mp[z][{x, y}] + 1;
				q[t].first = x - min(x, B - y);
				q[t++].second = y + min(x, B - y);
			}
			if (mp[z][{x, y}] + 1 < mp[z][{x + min(y, A - x), y - min(y, A - x)}])
			{
				mp[z][{x + min(y, A - x), y - min(y, A - x)}] = mp[z][{x, y}] + 1;
				q[t].first = x + min(y, A - x);
				q[t++].second = y - min(y, A - x);
			}
		}
		if (g)
		{
			cout << -1 << endl;
		}
	}
}
