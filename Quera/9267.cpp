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
ll n, par[MAX_N], c[MAX_N], t[MAX_N], so[MAX_N], root;
ll seg[4 * MAX_N], st[MAX_N], en[MAX_N], ans[MAX_N];
vector<int> adj[MAX_N], sten;
bool cmp(int x, int y)
{
	if (c[x] != c[y])
		return c[x] < c[y];
	return st[x] < st[y];
}
void dfs(int v, int p = 0)
{
	sten.pb(v);
	st[v] = sten.size();
	for (int u : adj[v])
	{
		if (u != p)
		{
			dfs(u, v);
		}
	}
	en[v] = sten.size();
}
void upd(int id, int b, int e, int l, ll val)
{
	if (l >= e || l < b)
		return;
	if (e - b == 1)
	{
		seg[id] = val;
		return;
	}
	int mid = (e + b) / 2;
	upd(id * 2, b, mid, l, val);
	upd(id * 2 + 1, mid, e, l, val);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
ll get(int id, int b, int e, int l, int r)
{
	if (l >= e || b >= r)
		return 0ll;
	if (l <= b && e <= r)
		return seg[id];
	int mid = (e + b) / 2;
	return get(id * 2, b, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> par[i] >> c[i] >> t[i];
		so[i] = i;
		if (par[i] == -1)
		{
			root = i;
		}
		else
		{
			adj[i].pb(par[i]);
			adj[par[i]].pb(i);
		}
	}
	dfs(root);
	sort(so + 1, so + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		ans[so[i]] = get(1, 1, n + 1, st[so[i]], en[so[i]] + 1);
		upd(1, 1, n + 1, st[so[i]], t[so[i]]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << endl;
	}
}
