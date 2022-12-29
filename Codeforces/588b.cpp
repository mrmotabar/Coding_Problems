#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int n;
	cin >> n;
	for (long long int i = 2; i < 1000000; i++)
	{
		while (n % (i * i) == 0)
		{
			n /= i;
		}
	}
	cout << n;
}
