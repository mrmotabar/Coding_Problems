#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ghadr(int a, int b)
{
	if (a - b >= 0)
	{
		return a - b;
	}
	else
	{
		return b - a;
	}
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int b[n];
	b[0] = ghadr(a[n - 1], a[0]);
	for (int i = 1; i < n; i++)
	{
		b[i] = ghadr(a[i - 1], a[i]);
	}
	int t = 0;
	for (int i = 1; i < n; i++)
	{
		if (b[i] < b[t])
		{
			t = i;
		}
	}
	if (t == 0)
	{
		cout << 1 << " " << n;
	}
	else
	{
		cout << t << " " << t + 1;
	}
}
