#include <iostream>
#include <cstdio>
using namespace std;
int maghsoom(int a, int b)
{
	int max;
	int z = a;
	if (b < z)
	{
		z = b;
	}
	for (int i = 1; i <= z; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}
	return max;
}
int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	bool c = true;
	for (int i = 0; c == true; i++)
	{
		if (i % 2 == 0)
		{
			n = n - maghsoom(a, n);
		}
		else
		{
			n = n - maghsoom(b, n);
		}
		if (n < 0)
		{
			c = false;
			if (i % 2 == 0)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
	}
}
