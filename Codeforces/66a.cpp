#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	unsigned long long int n;
	cin >> n;
	if (n < 128)
	{
		cout << "byte";
		return 0;
	}
	else if (n < 32768)
	{
		cout << "short";
		return 0;
	}
	else if (n < 2147483648)
	{
		cout << "int";
		return 0;
	}
	else if (n < 9223372036854775808)
	{
		cout << "long";
		return 0;
	}
	else
		cout << "BigInteger";
}
