#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	a = n / 2;
	if (n % 2 == 1)
	{
		b = a + 1;
	}
	else
	{
		b = a;
	}
	int min = n;
	while (a >= 0)
	{
		if (b % m == 0)
		{
			if (b < min)
			{
				min = b;
			}
		}
		a--;
		b++;
	}
	if (min == n)
	{
		if (n % m == 0)
		{
			cout << n;
		}
		else
		{
			cout << -1;
		}
	}
	else
	{
		cout << min;
	}
}
