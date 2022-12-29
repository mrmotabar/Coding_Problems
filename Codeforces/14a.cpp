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
	int si = 1000, sj = 1000, ei = 0, ej = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (c[i][j] == '*')
			{
				si = min(si, i);
				sj = min(sj, j);
				ei = max(ei, i);
				ej = max(ej, j);
			}
		}
	}
	for (int i = si; i <= ei; i++)
	{
		for (int j = sj; j <= ej; j++)
		{
			cout << c[i][j];
		}
		cout << endl;
	}
}
