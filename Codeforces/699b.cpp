/*mohammadreza motabar*/
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define F first
#define S second
int n, m;
char c[1000 + 10][1000 + 10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int maxri = 1, maxrj = 1, maxpi = 1, maxpj = 1;
	int maxci = 99999, maxcj = 99999, maxbi = 99999, maxbj = 99999;
	bool a[4] = {1, 1, 1, 1};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == '*' && i > maxpi)
			{
				maxpi = i;
				maxpj = j;
			}
			if (c[i][j] == '*' && j > maxrj)
			{
				maxrj = j;
				maxri = i;
			}
			if (c[i][j] == '*' && i < maxbi)
			{
				maxbi = i;
				maxbj = j;
			}
			if (c[i][j] == '*' && j < maxcj)
			{
				maxci = i;
				maxcj = j;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == '*')
			{
				if (i != maxri && j != maxpj)
				{
					a[0] = 0;
				}
				if (i != maxci && j != maxbj)
				{
					a[1] = 0;
				}
				if (i != maxci && j != maxpj)
				{
					a[2] = 0;
				}
				if (i != maxri && j != maxbj)
				{
					a[3] = 0;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (a[0] == 1)
		{
			cout << "YES" << endl;
			cout << maxri << " " << maxpj;
			return 0;
		}
		if (a[1] == 1)
		{
			cout << "YES" << endl;
			cout << maxci << " " << maxbj;
			return 0;
		}
		if (a[2] == 1)
		{
			cout << "YES" << endl;
			cout << maxci << " " << maxpj;
			return 0;
		}
		if (a[3] == 1)
		{
			cout << "YES" << endl;
			cout << maxri << " " << maxbj;
			return 0;
		}
	}
	cout << "NO";
}
