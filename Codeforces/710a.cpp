#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	if (int(s[0]) < int('h') && int(s[0]) > int('a') && int(s[1]) > int('1') && int(s[1]) < int('8'))
	{
		cout << 8;
	}
	else if ((s[0] == 'a' || s[0] == 'h') && (s[1] == '1' || s[1] == '8'))
	{
		cout << 3;
	}
	else
	{
		cout << 5;
	}
}
