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
ll n, m, st[MAX_N], en[MAX_N], dis[MAX_N], sq = 100;
ll ans[MAX_N], jam[MAX_N], temp[MAX_N];
vector<ll> adj[MAX_N], tab[MAX_N], sten;
pair<ll, pair<ll, ll>> qu[MAX_N];
void dfs(ll v, ll p = 0)
{
	dis[v] = dis[p] + 1;
	sten.pb(v);
	st[v] = sten.size();
	tab[dis[v]].pb(st[v]);
	for (ll u : adj[v])
	{
		if (u != p)
			dfs(u, v);
	}
	en[v] = sten.size();
}
ll jav(ll i)
{
	ll k = i - (i % sq);
	if (i % sq == 0)
		k = i - sq;
	ll v = qu[i].S.F;
	ll ret = ans[v];
	for (ll j = i - 1; j > k; j--)
	{
		if (qu[j].F == 1 && qu[j].S.F >= dis[v])
		{
			ll ind1 = lower_bound(tab[qu[j].S.F].begin(), tab[qu[j].S.F].end(), st[v]) - tab[qu[j].S.F].begin();
			ll ind2 = lower_bound(tab[qu[j].S.F].begin(), tab[qu[j].S.F].end(), en[v] + 1) - tab[qu[j].S.F].begin();
			ret += qu[j].S.S * (ind2 - ind1);
		}
	}
	return ret;
}
void dfs2(ll v, ll p = 0)
{
	temp[v] = 0;
	for (ll u : adj[v])
	{
		if (u != p)
		{
			dfs2(u, v);
			temp[v] += temp[u];
		}
	}
	temp[v] += jam[dis[v]];
	ans[v] += temp[v];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < n - 1; i++)
	{
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dis[0] = -1;
	dfs(1);
	ll x, y;
	for (ll i = 1; i <= m; i++)
	{
		cin >> qu[i].F;
		if (qu[i].F == 1)
		{
			cin >> qu[i].S.F >> qu[i].S.S;
			jam[qu[i].S.F] += qu[i].S.S;
		}
		else
		{
			cin >> qu[i].S.F;
			cout << jav(i) << endl;
		}
		if (i % sq == 0)
		{
			dfs2(1);
			memset(jam, 0, sizeof jam);
		}
	}
}
