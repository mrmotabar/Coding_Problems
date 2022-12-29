#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
		{
			s[i] = '1';
			s[i + 1] = '1';
			s[i + 2] = '1';
			i += 2;
		}
	}
	int u = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '1')
		{
			cout << s[i];
			u++;
		}
		int t = 0;
		if (s[i + 1] == '1' && u != 0)
		{
			for (int j = i; j < s.size(); j++)
			{
				if (s[j] != '1')
				{
					t++;
				}
			}
		}
		if (t > 0)
		{
			cout << " ";
		}
	}
}
