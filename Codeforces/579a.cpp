#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int x, b = 0;
	cin >> x;
	while (x > 0)
	{
		b += x % 2;
		x /= 2;
	}
	cout << b;
}
