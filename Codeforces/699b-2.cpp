/*mohammadreza motabar*/
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define F first
#define S second
int n, m, se;
char c[1000 + 10][1000 + 10];
int sa[1000 + 10], so[1000 + 10];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == '*')
			{
				se++;
				sa[i]++;
				so[j]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == '*')
			{
				if (sa[i] + so[j] - 1 == se)
				{
					cout << "YES" << endl;
					cout << i << " " << j;
					return 0;
				}
			}
			else
			{
				if (sa[i] + so[j] == se)
				{
					cout << "YES" << endl;
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	cout << "NO";
}
