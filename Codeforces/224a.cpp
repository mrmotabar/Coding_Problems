#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int a, b, c;
	cin >> a >> b >> c;
	long long int x = a * b * c;
	long long int i = 1;
	while (i * i < x)
	{
		i++;
	}
	x = i;
	long long int a1 = x / a;
	long long int a2 = x / b;
	long long int a3 = x / c;
	cout << (a1 + a2 + a3) * 4;
}
