#include <iostream>
#include <cstdio>
using namespace std;
long long n, sum, a[100000], m;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % 2 == 1)
		{
			m = a[i];
		}
		sum += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 1)
		{
			m = min(a[i], m);
		}
	}
	if (sum % 2 == 0)
	{
		cout << sum;
	}
	else
	{
		cout << sum - m;
	}
}
