#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<char, int> mp;
int main()
{
	mp['6'] = 0;
	mp['7'] = 1;
	mp['8'] = 2;
	mp['9'] = 3;
	mp['T'] = 4;
	mp['J'] = 5;
	mp['Q'] = 6;
	mp['K'] = 7;
	mp['A'] = 8;
	char hokm;
	string s1, s2;
	cin >> hokm >> s1 >> s2;
	if (s1[1] == hokm && s2[1] != hokm)
	{
		cout << "YES";
		return 0;
	}
	if (s1[1] == s2[1])
	{
		if (mp[s1[0]] > mp[s2[0]])
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}
	else
	{
		cout << "NO";
	}
}
