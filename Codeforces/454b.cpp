#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int main()
{
	int n;
	cin >> n;
	int p = 0, t = 0;
	bool dow = false, up = false;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i > 0 && a[i] < a[i - 1])
		{
			t++;
			p = i;
		}
	}
	if (t == 0)
	{
		cout << 0;
		return 0;
	}
	if (t == 1 && a[n - 1] <= a[0])
	{
		cout << n - p;
		return 0;
	}
	else
	{
		cout << -1;
	}
}
