#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int y = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '4' || s[i] == '7')
		{
			y++;
		}
	}
	if (y == 7 || y == 4)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
