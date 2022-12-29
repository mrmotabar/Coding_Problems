#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int i = 0;
	while (s[i] == 'a' && i < s.size())
	{
		i++;
	}
	if (i == s.size())
	{
		s[s.size() - 1] = 'z';
	}
	while (s[i] != 'a' && i < s.size())
	{
		s[i] = char(int(s[i]) - 1);
		i++;
	}
	cout << s;
}
