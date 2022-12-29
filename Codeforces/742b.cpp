#include <iostream>
#include <cstdio>
using namespace std;
long long int a[1000000];
long long int b[1000000];
long long int n, x, t;
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		a[b[i]]++;
	}
	if (x == 0)
	{
		long long int o = 0;
		for (int i = 0; i < 1000000; i++)
		{
			if (a[i] > 1)
			{
				o += a[i] * (a[i] - 1) / 2;
			}
		}
		cout << o;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[b[i] ^ x])
		{
			t += a[b[i] ^ x];
		}
	}
	cout << t / 2;
}
