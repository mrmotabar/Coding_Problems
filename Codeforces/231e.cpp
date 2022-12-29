/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9, MOD = 1000000007;
// voroodi
ll n, m;
vector<ll> adj[MAX_N];
ll from[MAX_N], to[MAX_N];
// dfs
vector<ll> adj2[MAX_N];
ll vis[MAX_N], andis[MAX_N], ind = 1, par[MAX_N], dis[MAX_N], w[MAX_N];
// lca
const ll maxl = 17 + 1;
ll bala[MAX_N][maxl], dp[MAX_N][maxl], ans, dis2[MAX_N];
// solve
ll solv[MAX_N];
void dfs(ll v, ll p)
{
	par[v] = p;
	dis[v] = dis[p] + 1;
	vis[v] = 1;
	for (ll u : adj[v])
	{
		if (!vis[u])
		{
			dfs(u, v);
		}
		else if (vis[u] && u != p && dis[u] < dis[v])
		{
			ll a = v;
			while (a != u)
			{
				andis[a] = ind;
				a = par[a];
			}
			andis[a] = ind;
			w[ind] = 1;
			ind++;
		}
	}
}
void dfslca(ll v, ll p)
{
	dis2[v] = dis2[p] + 1;
	bala[v][0] = p;
	dp[v][0] = w[v];
	for (ll i = 1; i <= 17; i++)
	{
		bala[v][i] = bala[bala[v][i - 1]][i - 1];
		dp[v][i] = dp[v][i - 1] + dp[bala[v][i - 1]][i - 1];
	}
	for (ll u : adj2[v])
	{
		if (u != p)
		{
			dfslca(u, v);
		}
	}
}
ll get_par(ll v, ll k)
{
	for (ll i = 0; i < maxl; i++)
	{
		if (k >> i & 1)
		{
			ans += dp[v][i];
			v = bala[v][i];
		}
	}
	return v;
}
ll lca(ll v, ll u)
{
	if (dis2[v] < dis2[u])
	{
		swap(v, u);
	}
	v = get_par(v, dis2[v] - dis2[u]);
	if (u == v)
	{
		ans += dp[v][0];
		return v;
	}
	for (ll i = maxl - 1; i >= 0; i--)
	{
		if (bala[v][i] != bala[u][i])
		{
			ans += dp[v][i];
			ans += dp[u][i];
			v = bala[v][i];
			u = bala[u][i];
		}
	}
	ans += dp[u][0];
	ans += dp[v][0];
	ans += w[bala[v][0]];
	return bala[v][0];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solv[0] = 1;
	for (ll i = 1; i < MAX_N; i++)
	{
		solv[i] = (solv[i - 1] * 2) % MOD;
	}
	cin >> n >> m;
	for (ll i = 1; i <= m; i++)
	{
		cin >> from[i] >> to[i];
		adj[from[i]].pb(to[i]);
		adj[to[i]].pb(from[i]);
	}
	dfs(1, 0);
	for (ll i = 1; i <= n; i++)
	{
		if (!andis[i])
		{
			andis[i] = ind;
			ind++;
		}
	}
	for (ll i = 1; i <= m; i++)
	{
		if (andis[from[i]] != andis[to[i]])
		{
			adj2[andis[from[i]]].pb(andis[to[i]]);
			adj2[andis[to[i]]].pb(andis[from[i]]);
		}
	}
	dfslca(1, 0);
	/*for(int i=1;i<ind;i++){
		cout<<i<<"   ";
		for(int j=0;j<maxl;j++){
			cout<<bala[i][j]<<" ";
		}
		cout<<endl;
	}*/
	/*for(int i=1;i<=n;i++){
		cout<<andis[i]<<" ";
	}
	cout<<endl;
	cout<<lca(andis[13],andis[11]);
	cout<<"  "<<ans;
	return 0;*/
	ll q;
	cin >> q;
	ll x, y;
	while (q--)
	{
		cin >> x >> y;
		ans = 0;
		lca(andis[x], andis[y]);
		cout << solv[ans] << endl;
	}
}
