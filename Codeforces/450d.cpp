/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 4e5 + 10, INF = 1e9;
ll n, m, k, dp[MAX_N], from[MAX_N], to[MAX_N], w[MAX_N];
ll train[MAX_N];
vector<pair<ll, ll>> adj[MAX_N];
set<pair<ll, ll>> st;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		from[i] = a;
		to[i] = b;
		w[i] = c;
		adj[a].pb({i, 0});
		adj[b].pb({i, 0});
	}
	for (int i = m + 1; i <= m + k; i++)
	{
		ll a, b;
		cin >> a >> b;
		from[i] = 1;
		to[i] = a;
		w[i] = b;
		adj[1].pb({i, 1});
		adj[a].pb({i, 1});
	}
	memset(dp, 63, sizeof dp);
	dp[1] = 0;
	st.insert({dp[1], 1});
	while (st.size())
	{
		auto x = *st.begin();
		st.erase(st.begin());
		for (auto u : adj[x.second])
		{
			int v = from[u.first] ^ to[u.first] ^ x.second;
			if (x.first + w[u.first] < dp[v])
			{
				st.erase({dp[v], v});
				dp[v] = x.first + w[u.first];
				st.insert({dp[v], v});
				train[v] = u.second;
			}
			else if (x.first + w[u.first] == dp[v])
			{
				if (train[v] == 1 && u.second == 0)
				{
					train[v] = 0;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 2; i <= n; i++)
	{
		if (train[i])
		{
			ans++;
		}
	}
	cout << k - ans;
}
