#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[5][5], o, p;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> a[j][i];
			if (a[j][i] == 1)
			{
				o = j;
				p = i;
			}
		}
	}
	o = o - 2;
	if (o < 0)
	{
		o = o * -1;
	}
	p = p - 2;
	if (p < 0)
	{
		p = p * -1;
	}
	cout << p + o;
}
