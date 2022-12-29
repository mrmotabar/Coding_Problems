#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	int a1, an;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			a1 = i;
		}
		if (a[i] == n)
		{
			an = i;
		}
	}
	int y;
	if ((an == n - 1 && a1 == 0) || (a1 == n - 1 && a1 == 0))
	{
		cout << n - 1;
		return 0;
	}
	else
	{
		if (an > a1)
		{
			if (n - 1 - an > a1)
			{
				y = n - 1 - a1;
			}
			else
			{
				y = an;
			}
		}
		else
		{
			if (n - 1 - a1 > an)
			{
				y = n - 1 - an;
			}
			else
			{
				y = a1;
			}
		}
	}
	if (y < 0)
	{
		y *= -1;
	}
	cout << y;
}
