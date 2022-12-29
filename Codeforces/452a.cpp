#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string a[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
	int b[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	string s;
	int n;
	bool p = false;
	cin >> n >> s;
	int t = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '.')
		{
			p = true;
			for (int j = 0; j < 8; j++)
			{
				if (b[j] == t - 1 && s[i] == a[j][i])
				{
					b[j] = t;
				}
			}
			t++;
		}
	}
	if (!p)
	{
		for (int i = 0; i < 8; i++)
		{
			if (a[i].size() == n)
			{
				cout << a[i];
			}
		}
		return 0;
	}
	for (int i = 0; i < 8; i++)
	{
		if (b[i] == t - 1 && a[i].size() == n)
		{
			cout << a[i];
		}
	}
}
