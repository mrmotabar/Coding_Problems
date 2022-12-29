/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	long long n, t;
	cin >> n >> t;
	if (n == 1 && t == 10)
	{
		cout << -1;
		return 0;
	}
	if (t != 10)
	{
		for (int i = 0; i < n; i++)
		{
			s += char(int('0') + t);
		}
		cout << s;
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			s += char(int('0') + 1);
		}
		s += '0';
		cout << s;
	}
}
