/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 100, INF = 1e9, maxl = 19;
int n, m, par[MAX_N], dis[MAX_N], se = 1, s[MAX_N], e[MAX_N], jad[MAX_N][maxl];
vector<int> adj[MAX_N], h[MAX_N];
void dfs(int v, int p = 0)
{
	dis[v] = dis[p] + 1;
	s[v] = se;
	h[dis[v]].pb(s[v]);
	jad[v][0] = p;
	for (int i = 1; i < maxl; i++)
	{
		jad[v][i] = jad[jad[v][i - 1]][i - 1];
	}
	for (int u : adj[v])
	{
		if (u != p)
		{
			se++;
			dfs(u, v);
		}
	}
	e[v] = se;
}
int get_par(int v, int p)
{
	for (int i = maxl - 1; i >= 0; i--)
	{
		if (p >> i & 1)
		{
			v = jad[v][i];
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
	for (int i = 1; i <= n; i++)
	{
		cin >> par[i];
		adj[i].pb(par[i]);
		adj[par[i]].pb(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (par[i] == 0)
		{
			dfs(i);
			se++;
		}
	}
	/*for(int i=0;i<=n;i++){
		for(int u:h[i]){
			cout<<u<<"  ";
		}
		cout<<endl;
	}
	return 0;*/
	// cout<<s[1]<<"  "<<e[1]<<endl;
	// return 0;
	cin >> m;
	while (m--)
	{
		int v, p;
		cin >> v >> p;
		int x = dis[v];
		v = get_par(v, p);
		// cout<<s[v]<<"  "<<e[v]<<endl;
		int l = lower_bound(h[x].begin(), h[x].end(), s[v] + 1) - h[x].begin();
		int r = upper_bound(h[x].begin(), h[x].end(), e[v]) - h[x].begin();
		if (r - l > 1)
		{
			cout << r - l - 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
}
