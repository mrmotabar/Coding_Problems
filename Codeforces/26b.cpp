#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int i = 0, par = 0, ans = 0;
	while (i < s.size())
	{
		if (s[i] == '(')
		{
			par++;
		}
		else
		{
			par--;
			if (par >= 0)
			{
				ans++;
			}
			if (par < 0)
			{
				par = 0;
			}
		}
		i++;
	}
	cout << ans * 2;
}
