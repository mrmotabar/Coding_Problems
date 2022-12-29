#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	int t1 = 0, t2 = 0, t3 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			t1++;
		}
		if (a[i] == 2)
		{
			t2++;
		}
		else if (a[i] == 3)
		{
			t3++;
		}
	}
	int b = min(t1, min(t2, t3));
	cout << b << endl;
	for (int i = 0; i < b; i++)
	{
		int x1 = 0;
		int x2 = 0;
		int x3 = 0;
		for (int j = 0; j < n; j++)
		{
			if (x1 == 1 && x2 == 1 && x3 == 1)
			{
				x1 = 0;
				x2 = 0;
				x3 = 0;
				cout << endl;
				break;
			}
			if (a[j] == 1 && x1 == 0)
			{
				cout << j + 1 << ' ';
				a[j] = 4;
				x1 = 1;
			}
			if (a[j] == 2 && x2 == 0)
			{
				cout << j + 1 << ' ';
				a[j] = 4;
				x2 = 1;
			}
			if (a[j] == 3 && x3 == 0)
			{
				cout << j + 1 << ' ';
				a[j] = 4;
				x3 = 1;
			}
		}
	}
}
