#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a = 0, b = 0, n, c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (b == 0 && c < 0)
		{
			a += (-1 * c);
		}
		if (c > 0)
		{
			b += c;
		}
		if (b > 0 && c < 0)
		{
			b = b + c;
		}
		if (b < 0)
		{
			while (b < 0)
			{
				b++;
				a++;
			}
		}
	}
	cout << a;
}
