#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n, d, m;
	cin >> n >> d;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < min(m, n); i++)
	{
		ans += a[i];
	}
	if (m > n)
	{
		ans -= (m - n) * d;
	}
	cout << ans;
}
