#include <iostream>
#include <cstdio>
using namespace std;
char c[1000000];
int main()
{
	int n, tx = 0, tX = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		if (c[i] == 'x')
		{
			tx++;
		}
		else
		{
			tX++;
		}
	}
	int h = n / 2 - min(tx, tX);
	cout << h << endl;
	if (tx < tX)
	{
		for (int i = 0; i < n && tx < tX; i++)
		{
			if (c[i] == 'X')
			{
				c[i] = 'x';
				tx++;
				tX--;
			}
		}
	}
	if (tX < tx)
	{
		for (int i = 0; i < n && tX < tx; i++)
		{
			if (c[i] == 'x')
			{
				c[i] = 'X';
				tx--;
				tX++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << c[i];
	}
}
