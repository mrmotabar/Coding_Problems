#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int a = (int(s[0]) - int('0')) * 10 + (int(s[1]) - int('0'));
	int b = (int(s[3]) - int('0')) * 10 + (int(s[4]) - int('0'));
	if (b < ((a % 10) * 10 + a / 10))
	{
		if (a % 10 <= 5)
		{
			if (a <= 5)
			{
				cout << 0 << a << ":" << (a % 10) * 10 + a / 10;
				return 0;
			}
			else
			{
				cout << a << ":" << (a % 10) * 10 + a / 10;
				return 0;
			}
		}
	}
	if ((a + 1) % 24 <= 5)
	{
		cout << 0 << (a + 1) % 24 << ":" << (a + 1) % 24 << 0;
		return 0;
	}
	if (a + 1 >= 6 && a + 1 <= 9)
	{
		a = 9;
	}
	if (a >= 15 && a <= 18)
	{
		a = 19;
	}
	cout << a + 1 << ":" << (a + 1) % 10 << (a + 1) / 10;
}
