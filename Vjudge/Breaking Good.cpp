#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 1e6, INF = 999999;
vector<int> adj[MAX_N], q;
bool doros[MAX_N], este[MAX_N];
int from[MAX_N], to[MAX_N], vaz[MAX_N], plast[MAX_N], dp[MAX_N], cokh[MAX_N], o[MAX_N];
int n, m, ans;
void pp(int v)
{
	if (v == n - 1)
	{
		return;
	}
	este[plast[v]] = 1;
	if (!vaz[plast[v]])
	{
		doros[plast[v]] = 1;
	}
	pp(from[plast[v]] ^ to[plast[v]] ^ v);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> from[i] >> to[i] >> vaz[i];
		from[i]--;
		to[i]--;
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = INF;
	}
	dp[n - 1] = 0;
	cokh[n - 1] = 0;
	int s = 0, e = 0;
	q.push_back(n - 1);
	e++;
	while (s < e)
	{
		int v = q[s++];
		for (int y : adj[v])
		{
			int u = from[y] ^ to[y] ^ v;
			if (dp[v] + 1 < dp[u])
			{
				q.push_back(u);
				e++;
				dp[u] = dp[v] + 1;
				if (vaz[y] == 0)
				{
					cokh[u] = cokh[v] + 1;
				}
				else
				{
					cokh[u] = cokh[v];
				}
				plast[u] = y;
			}
			else if (dp[v] + 1 == dp[u])
			{
				int x = cokh[v];
				if (vaz[y] == 0)
				{
					x++;
				}
				if (x < cokh[u])
				{
					cokh[u] = x;
					plast[u] = y;
				}
			}
		}
	}
	pp(0);
	for (int i = 0; i < m; i++)
	{
		if (este[i] && doros[i])
		{
			ans++;
			o[i] = 1;
		}
		else if (!este[i] && vaz[i])
		{
			ans++;
			o[i] = 1;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < m; i++)
	{
		if (o[i] == 1)
		{
			if (vaz[i] == 1)
			{
				cout << from[i] + 1 << " " << to[i] + 1 << " " << 0 << endl;
			}
			else
			{
				cout << from[i] + 1 << " " << to[i] + 1 << " " << 1 << endl;
			}
		}
	}
}
