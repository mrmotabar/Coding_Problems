#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a, n;
	cin >> n;
	a = n % 5;
	if (a == 0)
	{
		cout << (n / 5);
	}
	else
	{
		cout << (n / 5) + 1;
	}
}
