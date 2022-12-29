/*mohammadreza motabar*/
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define F first
#define S second
int n;
char c[20];
int a[20], b[20];
int main()
{
	cin >> n;
	bool u[5] = {0, 0, 0, 0, 0}, f = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		a[i] = int(c[i]) - int('0');
		if (a[i] == 0)
		{
			a[i] = 11;
			f = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1 || a[i] == 2 || a[i] == 3)
		{
			u[0] = 1;
		}
		if (a[i] == 1 || a[i] == 4 || a[i] == 7)
		{
			u[1] = 1;
		}
		if (a[i] == 3 || a[i] == 6 || a[i] == 9)
		{
			u[2] = 1;
		}
		if (a[i] == 7 || a[i] == 9 || a[i] == 11)
		{
			u[3] = 1;
		}
	}
	if (u[0] && f)
	{
		cout << "YES";
		return 0;
	}
	int t = 0;
	for (int i = 0; i < 4; i++)
	{
		if (u[i])
		{
			t++;
			;
		}
	}
	if (t == 4)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
}
