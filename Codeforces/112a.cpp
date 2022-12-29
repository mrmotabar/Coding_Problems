#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
	{
		if (int(s1[i]) < int('a'))
		{
			s1[i] = char(int(s1[i]) - int('A') + int('a'));
		}
		if (int(s2[i]) < int('a'))
		{
			s2[i] = char(int(s2[i]) - int('A') + int('a'));
		}
	}
	int t = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (int(s1[i]) > int(s2[i]))
		{
			t = 1;
			break;
		}
		if (int(s1[i]) < int(s2[i]))
		{
			t = -1;
			break;
		}
	}
	cout << t;
}
