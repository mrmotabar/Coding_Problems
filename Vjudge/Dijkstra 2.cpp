#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const ll MAX_N = 1e5 + 100, INF = 1e14, MAX_T = 1e6 + 1e4;
vector<pair<ll, ll>> adj[MAX_N];
ll d[MAX_N], plast[MAX_N], q[MAX_T], n, m;
bool mark[MAX_N];
void spfa(ll v)
{
	fill(d, d + MAX_N, INF);
	d[v] = 0;
	ll h = 0, t = 0;
	q[t++] = v;
	mark[v] = true;
	while (t - h > 0)
	{
		ll v = q[h++];
		mark[v] = false;
		for (auto e : adj[v])
		{
			ll u = e.first, w = e.second;
			if (d[v] + w < d[u])
			{
				d[u] = d[v] + w;
				plast[u] = v;
				if (!mark[u])
				{
					q[t++] = u;
					mark[u] = true;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll a, b, c;
	for (ll i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	spfa(n);
	if (d[1] == INF)
	{
		cout << -1;
		return 0;
	}
	cout << 1 << " ";
	ll x = 1;
	while (x != n)
	{
		cout << plast[x] << " ";
		x = plast[x];
	}
}
