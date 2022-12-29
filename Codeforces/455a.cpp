#include <cstdio>
#include <iostream>
using namespace std;
long long int d[100001];
long long int a[100001];
int main()
{
	long long int n;
	cin >> n;
	long long int x;
	long long int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x > maxx)
		{
			maxx = x;
		}
		a[x]++;
	}
	d[1] = a[1];
	for (int i = 2; i <= maxx; i++)
	{
		d[i] = max(d[i - 1], d[i - 2] + a[i] * i);
	}
	cout << d[maxx];
}
