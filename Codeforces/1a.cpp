#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long n, m, a;
	cin >> n >> m >> a;
	if (n % a != 0 && m % a != 0)
	{
		long long z, h;
		z = (a - (n % a)) + n;
		h = (a - (m % a)) + m;
		cout << (h * z) / (a * a);
	}
	else if (n % a == 0 && m % a != 0)
	{
		long long z, h;
		z = ((n % a)) + n;
		h = (a - (m % a)) + m;
		cout << (h * z) / (a * a);
	}
	else if (n % a != 0 && m % a == 0)
	{
		long long z, h;
		z = (a - (n % a)) + n;
		h = ((m % a)) + m;
		cout << (h * z) / (a * a);
	}
	else if (n % a == 0 && n % a == 0)
	{
		long long z, h;
		z = ((n % a)) + n;
		h = ((m % a)) + m;
		cout << (h * z) / (a * a);
	}
}
