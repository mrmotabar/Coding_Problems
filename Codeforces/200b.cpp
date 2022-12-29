#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long double x = 0.000000000000, n, a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		x += a;
	}
	cout << x / n;
}
