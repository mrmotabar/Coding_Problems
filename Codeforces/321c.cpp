/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, sz[MAX_N], ans[MAX_N];
vector<int> adj[MAX_N];
bool mark[MAX_N];
void dfs(int v, int par)
{
	sz[v] = 1;
	for (int u : adj[v])
	{
		if (u != par && !mark[u])
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
void decom(int v, int x)
{
	dfs(v, 0);
	int cent = fcent(v, sz[v]);
	// cout<<cent<<endl;
	mark[cent] = 1;
	ans[cent] = x;
	for (int u : adj[cent])
	{
		if (!mark[u])
		{
			decom(u, x + 1);
		}
	}
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
	decom(1, 0);
	for (int i = 1; i <= n; i++)
	{
		cout << char(ans[i] + int('A')) << " ";
	}
	cout << endl;
}
