#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	if (int(s[0]) > int('Z'))
	{
		s[0] = char(int(s[0]) - 32);
	}
	cout << s;
}
