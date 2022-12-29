#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int a[s.size()];
	int k = 1;
	int max1 = s.size() - 1;
	int max2 = s.size() - 1;
	for (int i = 0; i < s.size(); i++)
	{
		a[i] = int(s[i]) - int('0');
	}
	for (int i = s.size() - 2; i >= 0; i--)
	{
		if (a[i] % 2 == 0 && a[i] > a[s.size() - 1] && k == 1)
		{
			max1 = i;
			k = 0;
		}
		if (a[i] % 2 == 0 && a[i] < a[s.size() - 1])
		{
			max2 = i;
		}
	}
	if (max2 == s.size() - 1)
	{
		max2 = max1;
	}
	if (max2 == s.size() - 1)
	{
		cout << -1;
		return 0;
	}
	else
	{
		int x = a[max2];
		a[max2] = a[s.size() - 1];
		a[s.size() - 1] = x;
		for (int i = 0; i < s.size(); i++)
		{
			cout << a[i];
		}
	}
}
