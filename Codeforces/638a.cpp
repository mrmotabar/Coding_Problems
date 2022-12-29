#include <iostream>
#include <cstdio>
using namespace std;
int m, n;
int main()
{
	cin >> n >> m;
	if (m % 2 == 1)
	{
		cout << (m + 1) / 2;
	}
	else
	{
		cout << (n - m) / 2 + 1;
	}
}
