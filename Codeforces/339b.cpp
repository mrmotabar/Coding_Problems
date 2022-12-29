#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	long long n, t = 0;
	cin >> n;
	long long m;
	cin >> m;
	long long a[m];
	for (long long i = 0; i < m; i++)
	{
		cin >> a[i];
		if (i == 0)
		{
			t += (a[i] - 1);
		}
		else if (a[i] < a[i - 1])
		{
			t += (n - (a[i - 1] - a[i]));
		}
		else if (a[i] > a[i - 1])
		{
			t += (a[i] - a[i - 1]);
		}
	}
	cout << t;
}
