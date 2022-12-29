#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	for (int j = 0; j < s.size(); j += 2)
	{
		for (int i = 0; i < s.size() - j; i += 2)
		{
			if (s[i] == '3')
			{
				while (int(s[i]) > int(s[i + 2]) && (i + 2) < s.size())
				{
					char d = s[i];
					s[i] = s[i + 2];
					s[i + 2] = d;
				}
			}
			if (s[i] == '1')
			{
				while (int(s[i]) < int(s[i - 2]) && (i - 2) >= 0)
				{
					char d = s[i];
					s[i] = s[i - 2];
					s[i - 2] = d;
				}
			}
		}
	}
	cout << s;
}
