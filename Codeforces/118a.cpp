#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s, se;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != 'a' && s[i] != 'i' && s[i] != 'o' && s[i] != 'e' && s[i] != 'u' && s[i] != 'y' && s[i] != 'A' && s[i] != 'I' && s[i] != 'O' && s[i] != 'E' && s[i] != 'U' && s[i] != 'Y')
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				se += '.';
				se += char(s[i] + 32);
			}
			else
			{
				se += '.';
				se += s[i];
			}
		}
	}
	cout << se;
}
