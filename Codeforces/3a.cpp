#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int x, y;
	char f, g;
	cin >> f >> x >> g >> y;
	int a = int(f) - int('0');
	int b = int(g) - int('0');
	cout << max(abs(x - y), abs(a - b)) << endl;
	while (a != b || x != y)
	{
		if (a < b && x < y)
		{
			cout << "RU" << endl;
			x++;
			a++;
		}
		else if (a < b && x > y)
		{
			cout << "RD" << endl;
			x--;
			a++;
		}
		else if (a > b && x < y)
		{
			cout << "LU" << endl;
			x++;
			a--;
		}
		else if (a > b && x > y)
		{
			cout << "LD" << endl;
			x--;
			a--;
		}
		else if (a == b && x < y)
		{
			cout << "U" << endl;
			x++;
		}
		else if (a == b && x > y)
		{
			cout << "D" << endl;
			x--;
		}
		else if (a < b && x == y)
		{
			cout << "R" << endl;
			a++;
		}
		else if (a > b && x == y)
		{
			cout << "L" << endl;
			a--;
		}
	}
}
