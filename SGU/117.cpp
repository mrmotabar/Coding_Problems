#include <iostream>
#include <cstdio>
using namespace std;
int n, m, k;
int ld5(int x, long n)
{
	long long int ans, t;
	ans = 1;
	t = x;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			ans = (ans * t) % k;
		}
		t = (t * t) % k;
		n = n / 2;
	}
	return ans;
}
int main()
{
	cin >> n >> m >> k;
	int a[n], t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (ld5(a[i], m) == 0)
		{
			t++;
		}
	}
	cout << t;
}
