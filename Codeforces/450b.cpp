#include <iostream>
#include <cstdio>
using namespace std;
int a[10];
int main()
{
	int x, y, n;
	cin >> x >> y >> n;
	n %= 6;
	a[1] = x;
	a[2] = y;
	a[3] = y - x;
	a[4] = x * -1;
	a[5] = y * -1;
	a[6] = x - y;
	if (n == 0)
	{
		n = 6;
	}
	if ((a[n]) % (1000000007) < 0)
	{
		cout << (a[n]) % (1000000007) + 1000000007;
	}
	else
	{
		cout << (a[n]) % (1000000007);
	}
}
