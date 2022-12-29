#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int x = a[0] % 2 + a[1] % 2 + a[2] % 2;
	if (x < 2)
	{
		x = 0;
	}
	else
	{
		x = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != x)
		{
			cout << i + 1;
			return 0;
		}
	}
}
