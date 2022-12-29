#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> s[i];
	}
	int ans = 0;
	bool c = true;
	bool d = true;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (s[i][j] != 'B')
			{
				c = false;
				d = false;
			}
		}
		if (d == true)
		{
			ans++;
		}
		d = true;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (s[j][i] != 'B')
			{
				c = false;
				d = false;
			}
		}
		if (d == true)
		{
			ans++;
		}
		d = true;
	}
	if (c == true)
	{
		cout << 8;
		return 0;
	}
	cout << ans;
}
