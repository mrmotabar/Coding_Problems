#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	char c = s[0];
	for (int i = 0; i < s.size(); i++)
	{
		if (int('9') - int(s[i]) < int(s[i]) - int('0'))
		{
			s[i] = char(int('9') - int(s[i]) + int('0'));
		}
	}
	if (s[0] == '0')
	{
		s[0] = c;
	}
	cout << s;
}
