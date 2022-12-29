/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
ll n, ans, kom;
vector<ll> adj[MAX_N];
bool vis[MAX_N];
void dfs(int v)
{
	vis[v] = 1;
	kom++;
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			dfs(u);
		}
	}
}
bool nlucky(int a)
{
	while (a > 0)
	{
		if (a % 10 != 4 && a % 10 != 7)
		{
			return 1;
		}
		a /= 10;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		if (nlucky(c))
		{
			adj[a].pb(b);
			adj[b].pb(a);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			kom = 0;
			dfs(i);
			ans += kom * (n - kom) * (n - kom - 1);
		}
	}
	cout << ans;
}
