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
int n, ans;
vector<int> adj[MAX_N], root;
int dfs(int v)
{
	int dis = 0;
	for (int u : adj[v])
	{
		dis = max(dis, dfs(u));
	}
	return dis + 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int p;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		if (p == -1)
		{
			root.pb(i);
		}
		else
		{
			adj[p].pb(i);
		}
	}
	for (int u : root)
	{
		ans = max(ans, dfs(u));
	}
	cout << ans << endl;
}
