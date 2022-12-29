#include <iostream>
#include <cstdio>
using namespace std;
char c[1000][1000];
int main()
{
	int n, m;
	cin >> n >> m;
	bool ans = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
			if (j > 0)
				if (c[i][j] != c[i][j - 1])
				{
					ans = false;
				}
			if (i > 0)
				if (c[i][j] == c[i - 1][j])
				{
					ans = false;
				}
		}
	}
	if (ans)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
