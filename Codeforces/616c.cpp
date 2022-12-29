#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[1000000];
int vis[1000000];
int vis2[1000000];
pair<int, int> a[1010][1010];
int n, m;
int p = 0;
char c[1010][1010];
int h = 1;
void dfs(int v)
{
	vis[v] = 1;
	p++;
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
	a[x][y].first = p;
	a[x][y].second = h;
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
	for (int i = 1; i <= n * m; i++)
	{
		if (!vis[i])
		{
			int x = i / m;
			if (i % m > 0)
			{
				x++;
			}
			int y = i % m;
			if (y == 0)
			{
				y = m;
			}
			if (c[x][y] == '.')
			{
				p = 0;
				dfs(i);
				h++;
				a[x][y].first = p;
				a[x][y].second = h;
				dfs2(i);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j].first<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j].second<<" ";
		}
		cout<<endl;
	}
	return 0;*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == '.')
			{
				cout << c[i][j];
			}
			else
			{
				int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
				int x = a[i - 1][j].first + a[i][j - 1].first + a[i][j + 1].first + a[i + 1][j].first + 1;
				if (a[i][j - 1].second == a[i - 1][j].second && (a1 == 0 || a2 == 0))
				{
					x -= a[i][j - 1].first;
					a1 = 1;
					a2 = 1;
				}
				if (a[i][j - 1].second == a[i][j + 1].second && (a1 == 0 || a3 == 0))
				{
					x -= a[i][j - 1].first;
					a1 = 1;
					a3 = 1;
				}
				if (a[i][j - 1].second == a[i + 1][j].second && (a1 == 0 || a4 == 0) && j > 1 && i < n)
				{
					x -= a[i][j - 1].first;
					a1 = 1;
					a4 = 1;
				}
				if (a[i - 1][j].second == a[i][j + 1].second && (a2 == 0 || a3 == 0) && i > 0 && j < m)
				{
					x -= a[i - 1][j].first;
					a2 = 1;
					a3 = 1;
				}
				if (a[i - 1][j].second == a[i + 1][j].second && (a2 == 0 || a4 == 0) && i > 0 && i < n)
				{
					x -= a[i - 1][j].first;
					a2 = 1;
					a4 = 1;
				}
				if (a[i][j + 1].second == a[i + 1][j].second && (a3 == 0 || a4 == 0) && j > 0 && j < m)
				{
					x -= a[i][j + 1].first;
					a1 = 3;
					a2 = 4;
				}
				cout << x % 10;
			}
		}
		cout << endl;
	}
}
