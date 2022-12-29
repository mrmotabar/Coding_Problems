#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int main()
{
	int n, m, g;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> g;
		for (int j = g; j <= n; j++)
		{
			if (a[j] == 0)
			{
				a[j] = g;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
}
