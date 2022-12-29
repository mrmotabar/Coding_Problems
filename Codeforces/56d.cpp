#include <iostream>
#include <cstdio>
using namespace std;
int d[1100][1100];
string a, b;
void pp(int n, int m)
{
	if (!(n > 0 || m > 0))
		return;
	if (n > 0 && d[n][m] == d[n - 1][m] + 1)
	{
		cout << "DELETE " << n << endl;
		return pp(n - 1, m);
	}
	else if (m > 0 && d[n][m] == d[n][m - 1] + 1)
	{
		cout << "INSERT " << n + 1 << " " << b[m - 1] << endl;
		return pp(n, m - 1);
	}
	else
	{
		if (a[n - 1] != b[m - 1])
			cout << "REPLACE " << n << " " << b[m - 1] << endl;
		return pp(n - 1, m - 1);
	}
}
int main()
{
	cin >> a >> b;
	d[0][0] = 0;
	for (int i = 1; i <= max(a.size(), b.size()); i++)
	{
		d[i][0] = i;
		d[0][i] = i;
	}
	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				d[i][j] = d[i - 1][j - 1];
			}
			else
			{
				d[i][j] = min(d[i - 1][j], min(d[i][j - 1], d[i - 1][j - 1])) + 1;
			}
		}
	}
	cout << d[a.size()][b.size()] << endl;
	pp(a.size(), b.size());
}
