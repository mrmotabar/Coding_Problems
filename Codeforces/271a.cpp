#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int y, a[4];
	cin >> y;
	for (int i = y + 1; i < 10000; i++)
	{
		a[0] = i % 10;
		a[1] = (i % 100) / 10;
		a[2] = (i % 1000) / 100;
		a[3] = i / 1000;
		if (a[0] != a[1] && a[0] != a[2] && a[0] != a[3] && a[1] != a[2] && a[1] != a[3] && a[2] != a[3])
		{
			cout << i;
			break;
		}
	}
}
