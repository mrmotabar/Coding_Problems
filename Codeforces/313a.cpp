#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a;
	cin >> a;
	if (a >= 0)
	{
		cout << a;
	}
	else
	{
		int b = a / 10;
		int c = a % 10;
		int d = a / 10;
		int e = d - d % 10 + c;
		if (e > b)
		{
			cout << e;
		}
		else
		{
			cout << d;
		}
	}
}
