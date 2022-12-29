/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 3e5 + 10, INF = 1e9, mod = 1e9 + 7;
int n;
vector<int> adj[MAX_N];
ll dpdo[MAX_N], dpup[MAX_N];
ll pshr[MAX_N], pshl[MAX_N];
void dfsdo(int v, int p = 0)
{
	dpdo[v] = 1;
	for (int u : adj[v])
	{
		if (u != p)
		{
			dfsdo(u, v);
			dpdo[v] *= (dpdo[u] + 1);
			dpdo[v] %= mod;
		}
	}
}
void dfsup(int v, int p = 0)
{
	if (adj[v][0] != p)
		pshr[0] = dpdo[adj[v][0]] + 1;
	else
		pshr[0] = 1;
	for (int i = 1; i < adj[v].size(); i++)
	{
		if (adj[v][i] != p)
			pshr[i] = (pshr[i - 1] * (dpdo[adj[v][i]] + 1)) % mod;
		else
			pshr[i] = pshr[i - 1];
	}

	if (adj[v][adj[v].size() - 1] != p)
		pshl[adj[v].size() - 1] = dpdo[adj[v][adj[v].size() - 1]] + 1;
	else
		pshl[adj[v].size() - 1] = 1;
	for (int i = adj[v].size() - 1 - 1; i >= 0; i--)
	{
		if (adj[v][i] != p)
			pshl[i] = (pshl[i + 1] * (dpdo[adj[v][i]] + 1)) % mod;
		else
			pshl[i] = pshl[i + 1];
	}
	pshl[adj[v].size()] = 1;
	for (int i = 0; i < adj[v].size(); i++)
	{
		if (adj[v][i] != p)
		{
			if (i != 0 && i != adj[v].size() - 1)
				dpup[adj[v][i]] = (1 + (((pshr[i - 1] * pshl[i + 1]) % mod) * dpup[v]) % mod) % mod;
			else if (i == 0)
				dpup[adj[v][i]] = (1 + (pshl[i + 1] * dpup[v]) % mod) % mod;
			else if (i == adj[v].size() - 1)
				dpup[adj[v][i]] = (1 + (pshr[i - 1] * dpup[v]) % mod) % mod;
		}
	}

	for (int u : adj[v])
	{
		if (u != p)
		{
			dfsup(u, v);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int a;
		cin >> a;
		adj[i].pb(a);
		adj[a].pb(i);
	}
	dfsdo(1);
	dpup[1] = 1;
	dfsup(1);
	for (int i = 1; i <= n; i++)
	{
		cout << (dpdo[i] * dpup[i]) % mod << endl;
		// cout<<dpup[i]<<endl;
	}
}
