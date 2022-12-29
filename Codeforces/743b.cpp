#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long int n, k;
int main()
{
	cin >> n >> k;
	int x = 1;
	while (k >= 1)
	{
		if (k % 2 == 1)
		{
			cout << x;
			break;
		}
		k /= 2;
		x++;
	}
}
