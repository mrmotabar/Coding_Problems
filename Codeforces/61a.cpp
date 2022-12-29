#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s1, s2, s;
	cin >> s1 >> s2;
	if (s1[0] == s2[0])
	{
		s = '0';
	}
	else
	{
		s = '1';
	}
	for (int i = 1; i < s1.size(); i++)
	{
		if (s1[i] == s2[i])
		{
			s += '0';
		}
		else
		{
			s += '1';
		}
	}
	cout << s;
}
