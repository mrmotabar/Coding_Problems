#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string a;
	cin >> a;
	int t = a.size(), u = 0, y = 1;
	for (int i = 0; i < t; i++)
	{
		if (a[i] == a[i + 1])
		{
			y++;
		}
		else
		{
			y = 1;
		}
		if (y == 7)
		{
			u = 1;
		}
	}
	if (u == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
