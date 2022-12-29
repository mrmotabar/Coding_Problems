#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i <= s.size() / 2; i++)
	{
		int t = 0;
		if (s[i] != s[s.size() - 1 - i])
		{
			cout << "NO";
			return 0;
		}
		if (s[i] == 'T')
		{
		}
		else if (s[i] == 'A')
		{
		}
		else if (s[i] == 'O')
		{
		}
		else if (s[i] == 'I')
		{
		}
		else if (s[i] == 'U')
		{
		}
		else if (s[i] == 'Y')
		{
		}
		else if (s[i] == 'W')
		{
		}
		else if (s[i] == 'V')
		{
		}
		else if (s[i] == 'H')
		{
		}
		else if (s[i] == 'X')
		{
		}
		else if (s[i] == 'M')
		{
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
