#include <iostream>
#include <cstdio>
using namespace std;
int a[20][20];
int main()
{
	int n;
	cin >> n;
	int max = 1;
	for (int i = 1; i <= n; i++)
	{
		a[i][1] = 1;
		a[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			a[i][j] = a[i - 1][j] + a[i][j - 1];
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
		}
	}
	cout << max;
}
