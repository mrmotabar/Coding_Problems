/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll INF = 999999999;
ll fl[500 + 100][500 + 100], dp[500 + 100][500 + 100], adj[500 + 100][500 + 100];
int n, m;
int main()
{
	cin >> n >> m;
	for (int i = 0; i <= n + 10; i++)
	{
		for (int j = 0; j <= n + 10; j++)
		{
			fl[i][j] = INF;
			adj[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		fl[i][i] = 0;
	}
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a][b] = c;
		adj[b][a] = c;
		fl[a][b] = c;
		fl[b][a] = c;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				fl[i][j] = min(fl[i][j], fl[i][k] + fl[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (k != i && adj[i][k] + fl[k][j] == fl[i][j] && fl[i][j] != INF)
				{
					dp[i][j]++;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			a = 0;
			for (int k = 1; k <= n; k++)
			{
				if (fl[i][k] + fl[k][j] == fl[i][j] && fl[i][j] != INF)
				{
					a += dp[k][j];
				}
			}
			cout << a << " ";
		}
	}
	//	cout<<endl;
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=n;j++){
	//			cout<<dp[i][j]<<" ";
	//		}
	//		cout<<endl;
	//	}
}
