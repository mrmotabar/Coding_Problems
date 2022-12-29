#include <iostream>
#include <cstdio>
using namespace std;
int a[1000];
int b[5];
int c[1000];
int main()
{
	int k, n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		long long l = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
			int l = a[j];
			while (l >= 10)
			{
				int u = l % 10;
				l -= u;
				l /= 10;
				l += u;
			}
			a[j] = l;
		}
		c[0] = a[0];
		for (int j = 1; j < n; j++)
		{
			c[j] = c[j - 1] * a[j];
			int l = c[j];
			while (l >= 10)
			{
				int u = l % 10;
				l -= u;
				l /= 10;
				l += u;
			}
			c[j] = l;
		}
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += c[j];
		}
		int o = sum;
		while (o >= 10)
		{
			int u = o % 10;
			o -= u;
			o /= 10;
			o += u;
		}
		sum = o;
		b[i] = sum;
		sum = 0;
	}
	for (int i = 0; i < k; i++)
	{
		cout << b[i] << endl;
	}
}
