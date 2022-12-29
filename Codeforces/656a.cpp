#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	long long a = 1;
	for (int i = 0; i < n; i++)
	{
		a *= 2;
	}
	if (n > 12)
	{
		int b = 1;
		for (int i = 0; i < n - 13; i++)
		{
			b *= 2;
		}
		cout << a - (b * 100);
		return 0;
	}
	cout << a;
}
