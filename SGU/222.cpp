#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int s = 1;
	int u = m;
	if (n - m >= 0)
	{
		for (int i = n; i > n - m && i != 0; i--)
		{
			s *= i;
		}
		int z = 1;
		for (int i = 2; i <= n; i++)
		{
			z *= i;
		}
		for (int i = 1; i <= n - m; i++)
		{
			z /= i;
		}
		for (int i = 1; i <= (n - n + m); i++)
		{
			z /= i;
		}
		cout << s * z;
	}
	else
	{
		cout << 0;
	}
}
