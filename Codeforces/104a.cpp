#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	n -= 10;
	if (n == 1 || n == 11)
	{
		cout << 4;
	}
	if (n == 10)
	{
		cout << 15;
	}
	if (n > 1 && n < 10)
	{
		cout << 4;
	}
	if (n < 1 || n > 11)
	{
		cout << 0;
	}
}
