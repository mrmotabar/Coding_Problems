#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const long long int MAX_N = 1e6, INF = 99999999999;
ll n, m;
set<pair<ll, ll>> st;
vector<pair<ll, ll>> adj[MAX_N];
ll dp[MAX_N], plast[MAX_N];
void pp(int v)
{
	if (v == n)
	{
		return;
	}
	cout << plast[v] << " ";
	pp(plast[v]);
}
int main()
{
	cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	for (ll i = 0; i <= n; i++)
	{
		dp[i] = INF;
	}
	dp[n] = 0;
	st.insert({dp[n], n});
	while (st.size())
	{
		auto x = *st.begin();
		st.erase(st.begin());
		for (auto u : adj[x.second])
		{
			if (x.first + u.second < dp[u.first])
			{
				st.erase({dp[u.first], u.first});
				dp[u.first] = x.first + u.second;
				st.insert({dp[u.first], u.first});
				plast[u.first] = x.second;
			}
		}
	}
	if (dp[1] == INF)
	{
		cout << -1;
		return 0;
	}
	cout << 1 << " ";
	pp(1);
}
