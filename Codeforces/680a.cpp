#include <iostream>
#include <cstdio>
using namespace std;
int a[110];
int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int g;
		cin >> g;
		a[g]++;
		sum += g;
	}
	int max = 0;
	for (int i = 0; i < 110; i++)
	{
		if (a[i] == 2)
		{
			if (2 * i > max)
			{
				max = 2 * i;
			}
		}
		if (a[i] > 2)
		{
			if (3 * i > max)
			{
				max = 3 * i;
			}
		}
	}
	cout << sum - max;
}
