#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;
const ll INF = 1e16, MAX_N = 1000000;
vector<pair<pair<ll, ll>, ll>> adj[MAX_N];
set<pair<ll, ll>> st;
ll dp[MAX_N];
bool ta[MAX_N];
int main()
{
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	for (ll i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({{b, c}, 0});
		adj[b].push_back({{a, c}, 0});
	}
	for (ll i = 0; i < k; i++)
	{
		ll a, b;
		cin >> a >> b;
		adj[1].push_back({{a, b}, 1});
		adj[a].push_back({{1, b}, 1});
	}
	for (ll i = 0; i <= n + 10; i++)
	{
		dp[i] = INF;
	}
	dp[1] = 0;
	st.insert({dp[1], 1});
	while (st.size())
	{
		auto x = *st.begin();
		st.erase(st.begin());
		for (auto u : adj[x.second])
		{
			if (x.first + u.first.second < dp[u.first.first])
			{
				ta[u.first.first] = 0;
				if (u.second == 0)
				{
					ta[u.first.first] = 1;
				}
				st.erase({dp[u.first.first], u.first.first});
				dp[u.first.first] = x.first + u.first.second;
				st.insert({dp[u.first.first], u.first.first});
			}
			else if (x.first + u.first.second == dp[u.first.first])
			{
				if (u.second == 0)
				{
					ta[u.first.first] = 1;
				}
			}
		}
	}
	ll ans = 0;
	for (ll i = 2; i <= n; i++)
	{
		if (ta[i] == 0)
		{
			ans++;
		}
	}
	cout << k - ans;
}
