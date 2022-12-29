#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, l;
double d, a[1000 + 100];
int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	d = 0;
	for (int i = 1; i < n; i++)
	{
		d = max(d, double((a[i] - a[i - 1]) / 2));
	}
	d = max(double(a[0] - 0), d);
	d = max(double(l - a[n - 1]), d);
	cout << fixed << d;
}
