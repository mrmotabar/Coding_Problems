#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n, ans = 0;
int le[100000 + 10], ri[100000 + 10];
int main()
{
	cin >> n;
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> le[i] >> ri[i];
		a += le[i];
		b += ri[i];
	}
	int maax = abs(a - b);
	for (int i = 1; i <= n; i++)
	{
		int x = a - le[i] + ri[i];
		int y = b - ri[i] + le[i];
		if (abs(x - y) > maax)
		{
			ans = i;
			maax = abs(x - y);
		}
	}
	cout << ans;
}
