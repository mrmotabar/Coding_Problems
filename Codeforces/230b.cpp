#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
bool aval(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	long long int a;
	cin >> n;
	while (n--)
	{
		cin >> a;
		long long int x = sqrt(a);
		bool y = aval(x);
		if (x * x == a && y && x != 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
