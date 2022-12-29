#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m, x = 0;
	cin >> n >> m;
	for (; n > 0; n--)
	{
		x++;
		if (x % m == 0)
		{
			n++;
		}
	}
	cout << x;
}
