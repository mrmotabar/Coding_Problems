#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, x = 0;
	char a[50];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
		{
			x++;
		}
	}
	cout << x;
}
