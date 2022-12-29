#include <iostream>
#include <cstdio>
using namespace std;
int a[1000 * 1000];
int main()
{
	int n;
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] - a[i - 1] > 15)
		{
			cout << a[i - 1] + 15;
			return 0;
		}
		if (i == n)
		{
			if (90 - a[i] > 15)
			{
				cout << a[i] + 15;
				return 0;
			}
		}
	}
	cout << 90;
}
