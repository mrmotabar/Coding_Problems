#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		int u = n;
		while (u > 0)
		{
			ans += u % i;
			u /= i;
		}
	}
	for (int i = n - 2; i > 0; i--)
	{
		if (ans % i == 0 && (n - 2) % i == 0)
		{
			cout << ans / i << '/' << (n - 2) / i;
			return 0;
		}
	}
}
