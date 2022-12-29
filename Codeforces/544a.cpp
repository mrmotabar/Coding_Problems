#include <iostream>
#include <cstdio>
using namespace std;
int t[1000 * 1000 + 10];
int p[1000 * 1000 + 10];
int main()
{
	int k;
	string s;
	cin >> k >> s;
	int mot = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (t[int(s[i]) - int('0')] == 0)
		{
			mot++;
			t[int(s[i]) - int('0')]++;
		}
	}
	if (mot < k)
	{
		cout << "NO";
		return 0;
	}
	mot = 0;
	cout << "YES" << endl;
	for (int i = 0; i < s.size(); i++)
	{
		if (p[int(s[i]) - int('0')] == 0 && mot < k)
		{
			p[int(s[i]) - int('0')]++;
			mot++;
			if (mot > 1)
			{
				cout << endl;
			}
			cout << s[i];
		}
		else
		{
			cout << s[i];
		}
	}
}
