#include <iostream>
#include <cstdio>
using namespace std;
string s;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; s.size() < n + 20; i++)
	{
		if (i < 10)
		{
			s += char(i + int('0'));
		}
		else if (i > 9 && i < 100)
		{
			s += char(i / 10 + int('0'));
			s += char(i % 10 + int('0'));
		}
		else if (i > 99 && i < 1000)
		{
			s += char(i / 100 + int('0'));
			s += char((i % 100) / 10 + int('0'));
			s += char(i % 10 + int('0'));
		}
		else
		{
			s += char(i / 1000 + int('0'));
			s += char((i % 1000) / 100 + int('0'));
			s += char((i % 100) / 10 + int('0'));
			s += char(i % 10 + int('0'));
		}
	}
	cout << s[n - 1];
}
