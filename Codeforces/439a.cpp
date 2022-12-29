#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, d, m, a = (-1);
	cin >> n >> d;
	d -= (n - 1) * 10;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		d -= m;
	}
	if (d >= 0)
	{
		cout << ((d / 5) + ((n - 1) * 2));
	}
	else
	{
		cout << a;
	}
}
