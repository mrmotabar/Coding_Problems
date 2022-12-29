/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
vector<int> adj[200000 + 100];
bool vis[200000 + 100];
ll n, col[200000 + 100], inan, ind;
void dfs(int v, int d)
{
	if (d > ind)
	{
		ind = d;
		inan = v;
	}
	vis[v] = 1;
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			if (col[u] != col[v])
			{
				dfs(u, d + 1);
			}
			else
			{
				dfs(u, d);
			}
		}
	}
	vis[v] = 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> col[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	// cout<<ind<<"   "<<inan<<endl;
	dfs(inan, 0);
	// cout<<ind<<"   "<<inan<<endl;
	int ans = (ind / 2) + (ind % 2);
	cout << ans;
}
