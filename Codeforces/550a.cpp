#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int tab = 0, tba = 0, taba = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A') || (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B'))
		{
			taba++;
			i += 2;
		}
		else if (s[i] == 'A' && s[i + 1] == 'B')
		{
			tab = 1;
			i++;
		}
		else if (s[i] == 'B' && s[i + 1] == 'A')
		{
			tba = 1;
			i++;
		}
	}
	if (tab + tba + taba >= 2)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
