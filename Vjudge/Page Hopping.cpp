#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;
const int INF = 1e9;
vector<int> adj[1000];
int dp[1000][1000];
bool ha[1000];
int ans = 0, m = 0;
void bfs(int v)
{
	dp[v][v] = 0;
	int h = 0, t = 0;
	int q[1000];
	q[t++] = v;
	while (h < t)
	{
		int c = q[h++];
		for (int u : adj[c])
		{
			if (dp[v][c] + 1 < dp[v][u])
			{
				dp[v][u] = dp[v][c] + 1;
				q[t++] = u;
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			dp[i][j] = INF;
		}
	}
	int y = 1;
	while (true)
	{
		for (int i = 0; i < 1000; i++)
		{
			ha[i] = 0;
			adj[i].clear();
		}
		int a, b, l;
		for (l = 0; 1; l++)
		{
			cin >> a >> b;
			if (a == 0 && b == 0)
			{
				break;
			}
			adj[a].push_back(b);
			ha[a] = 1;
			ha[b] = 1;
		}
		if (l == 0 && a == 0 && b == 0)
		{
			break;
		}
		ans = 0;
		m = 0;
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				dp[i][j] = INF;
			}
			if (ha[i])
			{
				bfs(i);
			}
		}
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				if (dp[i][j] < INF && i != j)
				{
					m++;
					ans += dp[i][j];
				}
			}
		}
		cout << "Case " << y++ << ": average length between pages = " << setprecision(3) << fixed << showpoint << (double)ans / m << " clicks" << endl;
	}
}
