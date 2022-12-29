#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int p, m, c, k, r, v;
	cin >> p >> m >> c >> k >> r >> v;
	int m1, m2, m3;
	m1 = p / k;
	m2 = m / r;
	m3 = c / v;
	int z = m1;
	if (m2 < z)
	{
		z = m2;
	}
	if (m3 < z)
	{
		z = m3;
	}
	cout << z;
}
