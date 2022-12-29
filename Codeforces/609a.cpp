#include <iostream>
#include <cstdio>
using namespace std;
int n, m, a[100000], b, c;
int main()
{
	cin >> n >> m;
	c = n - 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		int b = a[i];
		int j = i - 1;
		while ((a[j] > b) && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = b;
	}
	b = 0;
	while (b < m)
	{
		b += a[c];
		c--;
	}
	cout << (n - c) - 1;
}
