#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	long long int r, x, y, z, w;
	cin >> r >> x >> y >> z >> w;
	long long int gx = x - z;
	long long int gy = y - w;
	long long int b = (gx * gx) + (gy * gy);
	long long int k = sqrt(b);
	if (k * k == b)
	{
		if (k % (2 * r) == 0)
		{
			cout << k / (2 * r);
		}
		else
		{
			cout << k / (2 * r) + 1;
		}
	}
	else
	{
		cout << k / (2 * r) + 1;
	}
}
