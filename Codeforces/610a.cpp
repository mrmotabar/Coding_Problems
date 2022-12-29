#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n % 2 != 0)
	{
		cout << 0;
	}
	else
	{
		n /= 2;
		if (n % 2 == 0)
		{
			cout << (n - 1) / 2;
		}
		else
		{
			cout << n / 2;
		}
	}
}
