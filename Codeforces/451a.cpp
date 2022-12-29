#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string a[2];
	a[0] = "Malvika";
	a[1] = "Akshat";
	int m, n;
	cin >> m >> n;
	int j = min(m, n);
	if (j % 2 == 0)
	{
		cout << a[0];
	}
	else
	{
		cout << a[1];
	}
}
