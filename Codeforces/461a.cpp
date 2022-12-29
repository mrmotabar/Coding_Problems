#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long int a[1000000];
int main()
{
	long long int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 1)
	{
		cout << a[0];
		return 0;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			sum += a[i] * n;
		}
		else
		{
			sum += a[i] * (i + 2);
		}
	}
	cout << sum;
}
