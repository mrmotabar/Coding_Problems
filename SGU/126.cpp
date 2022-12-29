#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m, t = 0;
	int a, b;
	cin >> n >> m;
	a = m;
	b = n;
	while (n > 0 && m > 0)
	{
		if (n < m)
		{
			m -= n;
			n *= 2;
		}
		else
		{
			n -= m;
			m *= 2;
		}
		t++;
		if (m == a || n == b && a != b)
		{
			cout << -1;
			return 0;
		}
		if (t > 40000000)
		{
			cout << -1;
			return 0;
		}
	}
	cout << t;
}
