#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
string k = "qwertyuiopasdfghjkl;zxcvbnm,./";
int main()
{
	char a;
	string s;
	cin >> a >> s;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (s[i] == k[j] && a == 'R')
			{
				cout << k[j - 1];
			}
			if (s[i] == k[j] && a == 'L')
			{
				cout << k[j + 1];
			}
		}
	}
}
