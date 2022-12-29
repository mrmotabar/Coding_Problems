#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if ((a + b + c + d + e) % 5 == 0 && (a + b + c + d + e) / 5 != 0)
	{
		cout << (a + b + c + d + e) / 5;
	}
	else
	{
		cout << -1;
	}
}
