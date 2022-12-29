/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll mod = 1000000007;
ll dp[100000 + 100][10 + 10], p1[100000 + 100], p2[100000 + 100], n, col[100000 + 100];
vector<ll> adj[100000 + 100], boy[100000 + 100];
void dfs(ll v, ll par)
{
	dp[v][col[v]] = 1;
	boy[v].push_back(-1);
	for (ll u : adj[v])
	{
		if (u != par)
		{
			dfs(u, v);
			if (col[v] == 1)
			{
				dp[v][1] *= (dp[u][1] + dp[u][0]);
				dp[v][1] %= mod;
			}
			else
			{
				dp[v][0] *= (dp[u][0] + dp[u][1]);
				dp[v][0] %= mod;
			}
			boy[v].push_back(u);
		}
	}
	if (col[v] == 0)
	{
		p1[0] = 1;
		p2[boy[v].size()] = 1;
		for (int i = 1; i < boy[v].size(); i++)
		{
			p1[i] = p1[i - 1] * (dp[boy[v][i]][0] + dp[boy[v][i]][1]);
			p1[i] %= mod;
		}
		for (int i = boy[v].size() - 1; i >= 1; i--)
		{
			p2[i] = p2[i + 1] * (dp[boy[v][i]][0] + dp[boy[v][i]][1]);
			p2[i] %= mod;
		}
		for (int i = 1; i < boy[v].size(); i++)
		{
			dp[v][1] += (dp[boy[v][i]][1] * ((p2[i + 1] * p1[i - 1]) % mod));
			dp[v][1] %= mod;
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int a;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a;
		adj[a].push_back(i + 1);
		adj[i + 1].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> col[i];
	}
	dfs(0, -1);
	cout << dp[0][1];
}
