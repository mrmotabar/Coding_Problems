#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[100000];
int vis[100000];
char c[60][60];
int ans = 0;
void dfs(int v, int v2)
{
	vis[v] = 1;
	for (int u : adj[v])
	{
		if (ans == 0)
		{
			if (u != v2 && vis[u] == 1)
			{
				ans = 1;
			}
			else if (u != v2)
			{
				dfs(u, v);
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == c[i][j + 1])
			{
				adj[(i - 1) * m + j].push_back((i - 1) * m + j + 1);
				adj[(i - 1) * m + j + 1].push_back((i - 1) * m + j);
			}
			if (c[i][j] == c[i + 1][j])
			{
				adj[(i - 1) * m + j].push_back(i * m + j);
				adj[i * m + j].push_back((i - 1) * m + j);
			}
		}
	}
	/*for(int i=1;i<=n*m;i++){
		for(int j=0;j<adj[i].size();j++){
			cout<<adj[i][j]<<"   ";
		}
		cout<<endl;
	}*/
	for (int i = 1; i <= n * m; i++)
	{
		if (vis[i] == 0)
		{
			dfs(i, i);
		}
	}
	if (ans > 0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}
