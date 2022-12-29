#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 1 && a[0] == 15)
	{
		cout << "DOWN";
		return 0;
	}
	else if (n == 1 && a[0] == 0)
	{
		cout << "UP";
		return 0;
	}
	else if (n == 1 && a[0] != 15 && a[0] != 0)
	{
		cout << -1;
		return 0;
	}
	if (a[n - 1] == 15)
	{
		cout << "DOWN";
		return 0;
	}
	if (a[n - 1] == 0)
	{
		cout << "UP";
		return 0;
	}
	if (a[n - 1] < a[n - 2])
	{
		cout << "DOWN";
		return 0;
	}
	else
	{
		cout << "UP";
	}
}
