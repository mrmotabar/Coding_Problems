#include <iostream>
#include <cstdio>
using namespace std;
int a[10000000 + 10];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int j = 0, s = 0, e = n - 1;
	int sum1 = 0, sum2 = 0;
	while (s <= e)
	{
		if (j % 2 == 1)
		{
			if (a[s] > a[e])
			{
				sum2 += a[s];
				s++;
			}
			else
			{
				sum2 += a[e];
				e--;
			}
		}
		else
		{
			if (a[s] > a[e])
			{
				sum1 += a[s];
				s++;
			}
			else
			{
				sum1 += a[e];
				e--;
			}
		}
		j++;
	}
	cout << sum1 << " " << sum2;
}
