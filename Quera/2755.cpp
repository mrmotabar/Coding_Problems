/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e3 + 10, INF = 1e9;
int n, m, k;
bool mark[MAX_N][MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		mark[a][b] = 1;
	}
	if (k % 2 == 1)
	{
		cout << 0;
		return 0;
	}
	if (k == n * m)
	{
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!mark[i][j])
			{
				cout << 1 << endl;
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
}
