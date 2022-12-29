#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		while (a[i] % 2 == 0 && a[i] != 0)
		{
			a[i] /= 2;
		}
		while (a[i] % 3 == 0 && a[i] != 0)
		{
			a[i] /= 3;
		}
		if (i > 0)
		{
			if (a[i] != a[i - 1])
			{
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
}
