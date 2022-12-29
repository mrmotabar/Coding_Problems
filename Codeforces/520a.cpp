#include <iostream>
#include <cstdio>
using namespace std;
int a[26];
int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (int(s[i]) < int('a'))
		{
			s[i] = char(int(s[i]) - int('A') + int('a'));
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[int(s[i]) - int('a')]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (a[i] == 0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
