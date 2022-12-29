/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 100 + 10, INF = 1e9;
int n, m, q, a[MAX_N][MAX_N];
int r[4] = {-1, 0, 1};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = -1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] != -1)
			{
				for (int k = 0; k < 3; k++)
				{
					for (int w = 0; w < 3; w++)
					{
						if (a[i + r[k]][j + r[w]] == -1)
						{
							a[i][j]++;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == -1)
			{
				cout << "* ";
			}
			else
			{
				cout << a[i][j] << " ";
			}
		}
		cout << endl;
	}
}
