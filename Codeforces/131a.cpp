#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string a;
	cin >> a;
	bool b = true;
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
			b = false;
	}
	if (b == true)
	{
		if (a[0] >= 'a' && a[0] <= 'z')
		{
			a[0] = char(int(a[0]) - int('a') + int('A'));
		}
		else
		{
			a[0] = char(int(a[0]) - int('A') + int('a'));
		}
		for (int i = 1; i < a.size(); i++)
		{
			a[i] = char(int(a[i]) - int('A') + int('a'));
		}
	}
	cout << a;
}
