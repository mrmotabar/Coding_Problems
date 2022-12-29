#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int x1, y1, x2, y2, x3, y3, x4, y4, q;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2)
	{
		q = y1 - y2;
		if (q < 0)
		{
			q *= -1;
		}
		x3 = x2 + q;
		y3 = y1;
		x4 = x3;
		y4 = y2;
	}
	else if (y1 == y2)
	{
		q = x1 - x2;
		if (q < 0)
		{
			q *= -1;
		}
		x3 = x1;
		y3 = y1 + q;
		x4 = x2;
		y4 = y3;
	}
	else
	{
		if (x1 - x2 == y1 - y2 || x1 - x2 == -(y1 - y2) || -(x1 - x2) == y1 - y2)
		{
			x3 = x1;
			y3 = y2;
			x4 = x2;
			y4 = y1;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4;
}
