/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll mod = 1000000007;
vector<ll> adj[2000 + 100];
ll d, n, val[2000 + 100], vis[2000 + 100];
ll dfs(ll v, ll avpar)
{
	if (val[avpar] - val[v] > d || val[v] > val[avpar] || (val[v] == val[avpar] && v < avpar))
	{
		return 1;
	}
	vis[v] = 1;
	ll ans = 1;
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			ans *= (dfs(u, avpar));
			ans %= mod;
		}
	}
	if (v != avpar)
	{
		ans++;
		ans %= mod;
	}
	vis[v] = 0;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> d >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += (dfs(i, i));
		ans %= mod;
	}
	cout << ans;
}
