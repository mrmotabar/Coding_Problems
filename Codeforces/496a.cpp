#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100000 + 10];
int main()
{
	int n;
	cin >> n;
	int maax = 0, miin = 9999999;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i > 1)
			if (abs(a[i] - a[i - 2]) < miin)
			{
				miin = abs(a[i] - a[i - 2]);
			}
		if (i > 0)
			if (abs(a[i] - a[i - 1]) > maax)
			{
				maax = abs(a[i] - a[i - 1]);
			}
	}
	cout << max(maax, miin);
}
