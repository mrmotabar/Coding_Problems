#include <iostream>
#include <cstdio>
using namespace std;
int n, a;
int main()
{
	cin >> n;
	if (n % 3 != 0)
	{
		a++;
	}
	cout << ((n / 3) * 2) + a;
}
