/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const int MAX_N = 2e5 + 10, INF = 1e9;
int n, m, name[MAX_N], ans[MAX_N], st[MAX_N], en[MAX_N], dis[MAX_N], fen[MAX_N], ind, in, in2, tname;
pii last[MAX_N];
map<string, int> mp;
vector<int> alaki;
vector<int> tab[MAX_N], adj[MAX_N], sten, thas;
vector<pair<pii, pii>> quu;
vector<pair<pii, int>> qu[MAX_N];
bool has[MAX_N];
void pre(int v, int par = -1)
{
	if (v == 0)
		dis[v] = -1;
	else
		dis[v] = dis[par] + 1;
	sten.pb(v);
	st[v] = sten.size() - 1;
	tab[dis[v]].pb(st[v]);
	for (int u : adj[v])
	{
		pre(u, v);
	}
	en[v] = sten.size() - 1;
}
void upd(int x, int v)
{
	while (x < MAX_N)
	{
		fen[x] += v;
		x += x & (-x);
	}
}
int get(int x)
{
	int anss = 0;
	while (x)
	{
		anss += fen[x];
		x -= x & (-x);
	}
	return anss;
}
void hal(int lev)
{
	sort(qu[lev].begin(), qu[lev].end());
	ind = 0;
	for (int i = 0; i < tab[lev].size() && ind < qu[lev].size(); i++)
	{
		if (last[name[sten[tab[lev][i]]]].F != 0 && last[name[sten[tab[lev][i]]]].S == lev)
		{
			upd(last[name[sten[tab[lev][i]]]].F, -1);
		}
		last[name[sten[tab[lev][i]]]].F = i + 1;
		last[name[sten[tab[lev][i]]]].S = lev;
		upd(last[name[sten[tab[lev][i]]]].F, 1);
		while (qu[lev][ind].F.F < tab[lev][i] && ind < qu[lev].size())
			ind++;
		while (ind < qu[lev].size())
		{
			in = lower_bound(tab[lev].begin(), tab[lev].end(), qu[lev][ind].first.first) - tab[lev].begin();
			if (in == tab[lev].size())
				in--;
			if (tab[lev][in] > qu[lev][ind].first.first)
				in--;
			if (in == i)
			{
				in2 = lower_bound(tab[lev].begin(), tab[lev].end(), qu[lev][ind].first.second) - tab[lev].begin();
				ans[qu[lev][ind].second] = get(in + 1) - get(in2);
				while (qu[lev][ind].F.F == qu[lev][ind + 1].F.F && qu[lev][ind].F.S == qu[lev][ind + 1].F.S && ind + 1 < qu[lev].size())
				{
					ans[qu[lev][ind + 1].S] = ans[qu[lev][ind].S];
					ind++;
				}
				ind++;
			}
			else
			{
				break;
			}
		}
	}
}
string inp()
{
	char c[22];
	scanf("%s", c);
	return c;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d", &n);
	string s, s1;
	int p;
	for (int i = 1; i <= n; i++)
	{
		s = inp();
		if (i == 1)
		{
			s1 = s;
		}
		scanf("%d", &p);
		if (mp.count(s) == 0)
		{
			tname++;
			mp[s] = tname;
		}
		name[i] = mp[s];
		adj[p].pb(i);
	}
	pre(0);
	scanf("%d", &m);
	int v, k;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &v, &k);
		// quu.pb({{dis[v]+k,en[v]},{st[v],i}});
		qu[dis[v] + k].pb({{en[v], st[v]}, i});
		if (!has[dis[v] + k])
		{
			thas.pb(dis[v] + k);
			has[dis[v] + k] = 1;
		}
	}
	// sort(quu.begin(),quu.end());
	// for(int i=0;i<m;i++){
	//	qu[quu[i].F.F].pb({{quu[i].F.S,quu[i].S.F},quu[i].S.S});
	// }
	for (int u : thas)
	{
		// memset(last,0,sizeof last);
		fill(fen, fen + tab[u].size() + 1, 0);
		hal(u);
	}
	for (int i = 1; i <= m; i++)
	{
		printf("%d\n", ans[i]);
	}
}
