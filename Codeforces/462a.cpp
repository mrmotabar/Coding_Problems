#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char a[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x = 0;
			if (a[i - 1][j] == 'o' && i > 0)
			{
				x++;
			}
			if (a[i + 1][j] == 'o' && i < n - 1)
			{
				x++;
			}
			if (a[i][j + 1] == 'o' && j < n - 1)
			{
				x++;
			}
			if (a[i][j - 1] == 'o' && j > 0)
			{
				x++;
			}
			if (x % 2 == 1)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}
