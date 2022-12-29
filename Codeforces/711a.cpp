#include <iostream>
#include <cstdio>
using namespace std;
string s[1000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	bool c = false;
	for (int i = 0; i < n; i++)
	{
		if (s[i][0] == 'O' && s[i][1] == 'O')
		{
			s[i][0] = '+';
			s[i][1] = '+';
			c = true;
			break;
		}
		else if (s[i][3] == 'O' && s[i][4] == 'O')
		{
			s[i][3] = '+';
			s[i][4] = '+';
			c = true;
			break;
		}
	}
	if (c == false)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << s[i] << endl;
		}
	}
}
