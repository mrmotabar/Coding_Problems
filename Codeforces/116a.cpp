#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n, a, b, m = 0, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		m = m - a;
		m += b;
		if (t < m)
		{
			t = m;
		}
	}
	cout << t;
}
