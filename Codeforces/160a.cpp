#include <cstdio>
#include <iostream>
using namespace std;
int a[101];
int main()
{
	int n, x, sum = 0, sum1 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[x]++;
		sum += x;
	}
	int t = 0;
	for (int i = 100; i >= 1; i--)
	{
		if (a[i] != 0)
		{
			while (a[i] > 0)
			{
				t++;
				sum1 += i;
				sum -= i;
				a[i]--;
				if (sum1 > sum)
				{
					cout << t;
					return 0;
				}
			}
		}
	}
}
