#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string a[n];
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s[s.size() - 1] == 'o' || s[s.size() - 1] == 'x' || (s[s.size() - 1] == 'h' && s[s.size() - 2] == 'c') || s[s.size() - 1] == 's')
		{
			a[i] = s + 'e' + 's';
		}
		else if (s[s.size() - 1] == 'y')
		{
			s[s.size() - 1] = 'i';
			a[i] = s + 'e' + 's';
		}
		else if (s[s.size() - 1] == 'f')
		{
			s[s.size() - 1] = 'v';
			a[i] = s + 'e' + 's';
		}
		else if (s[s.size() - 1] == 'e' && s[s.size() - 2] == 'f')
		{
			s[s.size() - 2] = 'v';
			a[i] = s + 's';
		}
		else
		{
			a[i] = s + 's';
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}
