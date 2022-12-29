#include <iostream>
#include <cstdio>
using namespace std;
int a[1000 + 10];
int main()
{
	int n;
	cin >> n;
	int h = 1, b = 0;
	while (n--)
	{
		int x;
		cin >> x;
		a[x]++;
		if (a[x] == 1)
		{
			b++;
		}
		if (a[x] > h)
		{
			h = a[x];
		}
	}
	cout << h << " " << b;
}
