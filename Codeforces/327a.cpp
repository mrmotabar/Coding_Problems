#include <iostream>
#include <cstdio>
using namespace std;
int a[1000];
int main()
{
	int n, t1 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			t1++;
		}
	}
	int maax = 0;
	for (int i = 0; i < n; i++)
	{
		int y1 = 0;
		int y0 = 0;
		for (int j = i; j < n; j++)
		{
			if (a[j] == 0)
			{
				y0++;
			}
			else
			{
				y1++;
			}
			maax = max(maax, t1 + y0 - y1);
		}
	}
	cout << maax;
}
