#include <iostream>
#include <cstdio>
using namespace std;
int t, n, a;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 0)
		{
			t++;
		}
	}
	if (n == 1)
	{
		if (t == 0)
		{
			cout << "YES";
			return 0;
		}
		if (t == n)
		{
			cout << "NO";
			return 0;
		}
	}
	if (t != 1)
	{
		cout << "NO";
		return 0;
	}
	else
	{
		cout << "YES";
	}
}
