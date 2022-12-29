/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 100, INF = 1e9, maxl = 19;
ll n, q;
vector<pair<ll, ll>> adj[MAX_N];
ll pre[MAX_N][maxl], suf[MAX_N][maxl], ans[MAX_N][maxl], pursh[MAX_N][maxl], dp[MAX_N][maxl], jav, dis[MAX_N], sufv, sufu;
void dfs(ll v, ll p, ll d)
{
	dis[v] = dis[p] + 1;
	dp[v][0] = p;
	pre[v][0] = max(0ll, d);
	suf[v][0] = max(0ll, d);
	ans[v][0] = max(0ll, d);
	pursh[v][0] = d;
	for (ll i = 1; i < maxl; i++)
	{
		dp[v][i] = dp[dp[v][i - 1]][i - 1];
		pre[v][i] = max(0ll, max(pursh[v][i - 1] + pre[dp[v][i - 1]][i - 1], pre[v][i - 1]));
		suf[v][i] = max(0ll, max(suf[dp[v][i - 1]][i - 1], pursh[dp[v][i - 1]][i - 1] + suf[v][i - 1]));
		pursh[v][i] = pursh[v][i - 1] + pursh[dp[v][i - 1]][i - 1];
		ans[v][i] = max(0ll, max(max(ans[v][i - 1], ans[dp[v][i - 1]][i - 1]), suf[v][i - 1] + pre[dp[v][i - 1]][i - 1]));
	}
	for (auto u : adj[v])
	{
		if (u.first != p)
		{
			dfs(u.first, v, u.second);
		}
	}
}
ll get_par2(ll v, ll k)
{
	for (ll i = 0; i < maxl; i++)
	{
		if (k >> i & 1)
		{
			jav = max(jav, max(ans[v][i], pre[v][i] + sufv));
			sufv = max(0ll, max(sufv + pursh[v][i], suf[v][i]));
			v = dp[v][i];
		}
	}
	return v;
}
ll lca2(ll v, ll u)
{
	if (dis[v] < dis[u])
	{
		swap(v, u);
	}
	v = get_par2(v, dis[v] - dis[u]);
	return v;
}
ll get_par1(ll v, ll k)
{
	for (ll i = 0; i < maxl; i++)
	{
		if (k >> i & 1)
		{
			sufv = max(0ll, max(sufv + pursh[v][i], suf[v][i]));
			v = dp[v][i];
		}
	}
	return v;
}
ll lca1(ll v, ll u)
{
	if (dis[v] < dis[u])
	{
		swap(v, u);
	}
	v = get_par1(v, dis[v] - dis[u]);
	if (u == v)
	{
		return v;
	}
	for (ll i = maxl - 1; i >= 0; i--)
	{
		if (dp[v][i] != dp[u][i])
		{
			sufv = max(0ll, max(sufv + pursh[v][i], suf[v][i]));
			sufu = max(0ll, max(sufu + pursh[u][i], suf[u][i]));
			v = dp[v][i];
			u = dp[u][i];
		}
	}
	sufv = max(0ll, max(sufv + pursh[v][0], suf[v][0]));
	sufu = max(0ll, max(sufu + pursh[u][0], suf[u][0]));
	jav = max(0ll, sufv + sufu);
	return dp[v][0];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n - 1; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}
	dfs(1, 0, 0);
	for (ll i = 0; i < q; i++)
	{
		ll x, y;
		cin >> x >> y;
		jav = 0, sufv = 0, sufu = 0;
		ll a, b, c;
		ll l = lca1(x, y);
		a = jav;
		jav = 0, sufv = 0, sufu = 0;
		lca2(x, l);
		b = jav;
		jav = 0, sufv = 0, sufu = 0;
		lca2(y, l);
		c = jav;
		cout << max(0ll, max(a, max(b, c)));
		if (i < q - 1)
		{
			cout << endl;
		}
	}
}
