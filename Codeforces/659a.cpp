#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	a += b;
	while (a > n && a > 1)
	{
		a -= n;
	}
	while (a < 1)
	{
		a += n;
	}
	cout << a;
}
