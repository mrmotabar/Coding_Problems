/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e3 + 10, INF = 1e9, MAX_T = 100 + 10;
int t, n, m, k, q, tedad;
vector<int> adj[MAX_T][MAX_N], anda[MAX_T];
bool vis[MAX_T][MAX_N];
void dfs(int v)
{
	vis[t][v] = 1;
	tedad++;
	for (int u : adj[t][v])
	{
		if (!vis[t][u])
		{
			dfs(u);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k >> q;
		int a, b, sum = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			adj[t][b].pb(a);
			adj[t][a].pb(b);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!vis[t][i])
			{
				tedad = 0;
				dfs(i);
				anda[t].pb(tedad);
			}
		}
		sort(anda[t].begin(), anda[t].end());
		int y = 0;
		if (anda[t].size() > k)
		{
			y = anda[t].size() - k;
		}
		for (int i = anda[t].size() - 1; i >= y; i--)
		{
			sum += anda[t][i];
		}
		if (sum >= q)
		{
			cout << "Satisfied" << endl;
		}
		else
		{
			cout << "Unsatisfied" << endl;
		}
	}
}
