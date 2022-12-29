#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n], max = 0, t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] >= a[i - 1] && i != 0)
		{
			t++;
		}
		if (a[i] < a[i - 1])
		{
			if (t > max)
			{
				max = t;
			}
			t = 0;
		}
		if (i == n - 1)
		{
			if (t > max)
			{
				max = t;
			}
		}
	}
	cout << max + 1;
}
