#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
bool bar(int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	while (!bar(n))
	{
		for (int i = n - 1; i > 0; i--)
		{
			if (a[i] > a[i - 1])
			{
				a[i] -= a[i - 1];
			}
		}
		sort(a, a + n);
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	cout << sum;
}
