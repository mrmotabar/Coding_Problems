#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int t = -1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			t = i;
			break;
		}
	}
	if (t == -1)
	{
		for (int i = 0; i < s.size() - 1; i++)
		{
			cout << s[i];
		}
	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (i != t)
			{
				cout << s[i];
			}
		}
	}
}
