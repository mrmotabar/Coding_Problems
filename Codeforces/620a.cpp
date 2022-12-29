#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int x1, x2, y1, y2, a, b;
	cin >> x1 >> y1 >> x2 >> y2;
	a = x1 - x2;
	b = y1 - y2;
	if (a < 0)
	{
		a = a * (-1);
	}
	if (b < 0)
	{
		b = b * (-1);
	}
	if (b < a)
	{
		cout << a;
	}
	else
	{
		cout << b;
	}
}
