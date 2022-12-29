#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int n, a, b;
	cin >> n;
	long long int k;
	cin >> k;
	if (n % 2 == 1)
	{
		a = (n / 2) + 1;
		b = n / 2;
	}
	else
	{
		a = n / 2;
		b = n / 2;
	}
	if (k > a)
	{
		k = k - a;
		cout << k * 2;
	}
	else
	{
		cout << (2 * k) - 1;
	}
}
