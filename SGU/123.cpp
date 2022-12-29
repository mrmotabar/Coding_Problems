#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	int sum = 0;
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		sum += a[i];
	}
	if (n > 2)
	{
		cout << sum + 2;
	}
	if (n == 2 || n == 1)
	{
		cout << n;
	}
}
