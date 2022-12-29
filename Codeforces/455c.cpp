/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAX_N = 3e5 + 100, INF = 1e9;
ll n, m, q;
ll par[MAX_N], ma[MAX_N];
vector<int> adj[MAX_N];
bool vis[MAX_N];
int get_root(int v)
{
	return (!par[v] ? v : par[v] = get_root(par[v]));
}
pll dfs(int v, int dis, int pas)
{
	pll a = {v, dis}, b;
	for (int u : adj[v])
	{
		if (u != pas)
		{
			b = dfs(u, dis + 1, v);
			if (b.second > a.second)
			{
				a = b;
			}
		}
	}
	return a;
}
ll dfs2(int v, int dis)
{
	vis[v] = 1;
	// cout<<v<<"   ";
	ll a = dis, b;
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			b = dfs2(u, dis + 1);
			if (b > a)
			{
				a = b;
			}
			par[u] = v;
		}
	}
	return a;
}
void merge(int v, int u)
{
	int rv = get_root(v);
	int ru = get_root(u);
	if (ru == rv)
	{
		return;
	}
	par[ru] = rv;
	ma[rv] = max(max(ma[rv], ma[ru]), ma[ru] / 2 + (ma[ru] % 2) + ma[rv] / 2 + (ma[rv] % 2) + 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			pll a;
			a = dfs(i, 0, -1);
			// if(i==1){
			//	cout<<a.first;
			// }
			ma[a.first] = dfs2(a.first, 0);
			// cout<<endl;
			// cout<<ma[a.first]<<"   "<<i<<"  "<<get_root(i)<<endl;
		}
	}
	int te, x, y;
	while (q--)
	{
		cin >> te;
		if (te == 1)
		{
			cin >> x;
			cout << ma[get_root(x)] << endl;
		}
		else
		{
			cin >> x >> y;
			merge(x, y);
		}
	}
}
