/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e6 + 10, INF = 1e9;
int n, sz[MAX_N];
vector<int> adj[MAX_N];
bool mark[MAX_N];
void dfs(int v, int par)
{
	sz[v] = 1;
	for (int u : adj[v])
	{
		if (!mark[u] && u != par)
		{
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
}
int fcent(int v, int kol)
{
	bool boo = 0;
	int pr = 0;
	while (!boo)
	{
		boo = 1;
		for (int u : adj[v])
		{
			if (u != pr && !mark[u] && sz[u] > kol / 2)
			{
				pr = v;
				v = u;
				boo = 0;
				break;
			}
		}
	}
	return v;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int p = 1;
	while (1)
	{
		dfs(p, 0);
		int cnt = fcent(p, sz[p]);
		mark[cnt] = 1;
		cout << cnt << endl;
		cin >> p;
		if (p == 0)
			break;
	}
}
