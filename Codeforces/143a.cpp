#include <iostream>
#include <cstdio>
using namespace std;
int c[22];
int main()
{
	int a[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> a[i];
	}
	int b[4];
	b[0] = (a[0] + a[2] - a[5]) / 2;
	b[1] = a[0] - b[0];
	b[2] = a[2] - b[0];
	b[3] = a[3] - b[1];

	c[b[0]]++;
	c[b[1]]++;
	c[b[2]]++;
	c[b[3]]++;
	for (int i = 1; i < 21; i++)
	{
		if (c[i] > 1)
		{
			cout << -1;
			return 0;
		}
	}
	for (int i = 10; i < 21; i++)
	{
		if (c[i] > 0)
		{
			cout << -1;
			return 0;
		}
	}
	if (c[0] > 0)
	{
		cout << -1;
		return 0;
	}
	if ((b[0] + b[1] != a[0]) || (b[2] + b[3] != a[1]) || (b[0] + b[2] != a[2]) || (b[1] + b[3] != a[3]) || (b[0] + b[3] != a[4]) || (b[2] + b[1] != a[5]))
	{
		cout << -1;
		return 0;
	}
	cout << b[0] << " " << b[1] << endl
		 << b[2] << " " << b[3];
}
