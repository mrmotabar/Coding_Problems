#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int i = 0;
	bool c = true;
	while (i < s.size())
	{
		while (s[i] == '/' && i < s.size())
		{
			i++;
			if (i == s.size() && c == true)
			{
				cout << '/';
			}
		}
		int x = i;
		while (s[i] != '/' && i < s.size())
		{
			if (i == x)
			{
				cout << '/';
			}
			c = false;
			cout << s[i];
			i++;
		}
	}
}
