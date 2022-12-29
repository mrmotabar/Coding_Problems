#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s, t;
	int u = 0, l = 0, p = 0, y = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'h' && u < 1)
		{
			u++;
			t += 'h';
		}
		if (s[i] == 'e' && l < 1 && u == 1)
		{
			l++;
			t += 'e';
		}
		if (s[i] == 'l' && y < 2 && u == 1 && l == 1)
		{
			y++;
			t += 'l';
		}
		if (s[i] == 'o' && p < 1 && u == 1 && l == 1 && y == 2)
		{
			p++;
			t += 'o';
		}
	}
	if (t == "hello")
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
