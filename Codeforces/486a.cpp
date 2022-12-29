#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	long long int n, x;
	cin >> n;
	if (n % 2 == 0)
	{
		cout << n / 2;
	}
	else if (n % 2 == 1)
	{
		x = n - 1;
		cout << (x / 2) - n;
	}
}
