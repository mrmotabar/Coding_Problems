#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[1000000];
int vis[1000000];
int vis2[1000000];
int f[1010][1010];
int n, m, k;
char c[10000][10000];
int p = 0;
void dfs(int v)
{
	vis[v] = 1;
	int x = v / m;
	if (v % m > 0)
	{
		x++;
	}
	int y = v % m;
	if (y == 0)
	{
		y = m;
	}
	if (c[x - 1][y] == '*' && x > 1)
	{
		p++;
	}
	if (c[x + 1][y] == '*' && x < n)
	{
		p++;
	}
	if (c[x][y + 1] == '*' && y < m)
	{
		p++;
	}
	if (c[x][y - 1] == '*' && y > 0)
	{
		p++;
	}
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			dfs(u);
		}
	}
}
void dfs2(int v)
{
	vis2[v] = 1;
	int x = v / m;
	if (v % m > 0)
	{
		x++;
	}
	int y = v % m;
	if (y == 0)
	{
		y = m;
	}
	f[x][y] = p;
	for (int u : adj[v])
	{
		if (!vis2[u])
		{
			dfs2(u);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
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
			if (c[i][j] == '.')
			{
				if (c[i][j] == c[i][j + 1] && j < m)
				{
					adj[(i - 1) * m + j].push_back((i - 1) * m + j + 1);
					adj[(i - 1) * m + j + 1].push_back((i - 1) * m + j);
				}
				if (c[i][j] == c[i + 1][j] && i < n)
				{
					adj[(i - 1) * m + j].push_back(i * m + j);
					adj[i * m + j].push_back((i - 1) * m + j);
				}
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		int v = (a - 1) * m + b;
		if (vis[v] == 0)
		{
			p = 0;
			dfs(v);
			cout << p << endl;
			dfs2(v);
		}
		else
		{
			cout << f[a][b] << endl;
		}
	}
}
