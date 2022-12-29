#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	int t = 0;
	cin >> n;
	char s[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (s[i][j] == '#' && s[i - 1][j] == '#' && s[i][j - 1] == '#' && s[i][j + 1] == '#' && s[i + 1][j] == '#')
			{
				t++;
				s[i - 1][j] = '.';
				s[i][j - 1] = '.';
				s[i][j + 1] = '.';
				s[i + 1][j] = '.';
				s[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == '#')
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}
