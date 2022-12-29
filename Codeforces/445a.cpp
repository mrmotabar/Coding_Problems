#include <iostream>
#include <cstdio>
using namespace std;
char c[1000][1000];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (c[i][j] == '.')
			{
				if ((i + j) % 2 == 1)
				{
					c[i][j] = 'B';
				}
				else
				{
					c[i][j] = 'W';
				}
			}
			cout << c[i][j];
		}
		cout << endl;
	}
}
