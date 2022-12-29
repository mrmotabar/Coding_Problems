/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 3000 + 100, INF = 1e9;
int n, m, adj[MAX_N][MAX_N];
bool hazv[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j && adj[i][j] == 0 && !hazv[i] && !hazv[j])
			{
				hazv[i] = 1;
				hazv[j] = 1;
			}
		}
	}
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!hazv[i] && t < n / 3)
		{
			cout << i << " ";
			t++;
		}
	}
}
