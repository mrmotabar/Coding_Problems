/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 5000 + 1, INF = 2e9;
int t, dp[MAX_N][MAX_N], vo[MAX_N], par[MAX_N][MAX_N], st[MAX_N];
vector<pii> adj[MAX_N];
vector<int> dag;
short n, m;
void fdag()
{
	int ind = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vo[i] == 0)
		{
			st[ind] = i;
			ind++;
		}
	}
	while (ind)
	{
		int x = st[ind - 1];
		ind--;
		dag.pb(x);
		for (pii u : adj[x])
		{
			vo[u.F]--;
			if (vo[u.F] == 0)
			{
				st[ind] = u.F;
				ind++;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> t;
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a].pb({b, c});
		vo[b]++;
	}
	fdag();
	memset(dp, 63, sizeof dp);
	dp[n][0] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			for (pii u : adj[dag[i]])
			{
				if (dp[dag[i]][j] > dp[u.F][j - 1] + u.S)
				{
					dp[dag[i]][j] = dp[u.F][j - 1] + u.S;
					par[dag[i]][j] = u.F;
				}
			}
		}
	}
	int ans;
	for (int i = 0; i <= m; i++)
	{
		if (dp[1][i] <= t)
		{
			ans = i;
		}
	}
	cout << ans + 1 << "\n";
	int v = 1;
	while (ans)
	{
		cout << v << ' ';
		v = par[v][ans];
		ans--;
	}
	cout << v;
}
