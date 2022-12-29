#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			t++;
		}
	}
	if (t == n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			cout << a[i] << " ";
		}
		cout << 2;
		return 0;
	}
	sort(a, a + n);
	cout << 1 << " ";
	for (int i = 0; i < n - 1; i++)
	{
		cout << a[i] << " ";
	}
}
