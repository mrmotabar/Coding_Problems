#include <iostream>
#include <cstdio>
using namespace std;
long long zarb(long long a, int n)
{
	for (int i = 0; i <= n; i++)
	{
		a *= 2;
	}
	return a;
}
int main()
{
	int n;
	long long a = 1;
	cin >> n;
	cout << zarb(a, n) - 2;
}
