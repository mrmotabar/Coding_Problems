#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	int count = 0;
	bool capon = false;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			count++;
		}
	}
	if (count > s.size() - count)
		capon = true;
	if (capon)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = char(s[i] - 32);
		}
	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = char(s[i] + 32);
			}
		}
	}
	cout << s;
}
