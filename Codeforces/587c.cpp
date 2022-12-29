/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9, MAX_L = 18;
int n, m, q, dp[MAX_N][MAX_L], dis[MAX_N];
vector<int> adj[MAX_N], zen[MAX_N];
vector<int> mine[MAX_N][MAX_L], komak, ans;
void mergesort(vector<int> &a, vector<int> &b, vector<int> &c)
{
	vector<int> khor;
	int s1 = 0, s2 = 0, t = 0;
	while (s1 < 10 && s1 < a.size() && s2 < 10 && s2 < b.size())
	{
		if (a[s1] < b[s2])
		{
			khor.pb(a[s1]);
			s1++;
			t++;
		}
		else
		{
			khor.pb(b[s2]);
			s2++;
			t++;
		}
	}
	if (t < 11)
	{
		if (s1 < a.size())
		{
			while (t < 11 && s1 < a.size())
			{
				khor.pb(a[s1]);
				s1++;
				t++;
			}
		}
		if (s2 < b.size())
		{
			while (t < 11 && s2 < b.size())
			{
				khor.pb(b[s2]);
				s2++;
				t++;
			}
		}
	}
	c = khor;
}
void dfs(int v, int p)
{
	dp[v][0] = p;
	dis[v] = dis[p] + 1;
	mine[v][0] = zen[v];
	for (int i = 1; i < MAX_L; i++)
	{
		dp[v][i] = dp[dp[v][i - 1]][i - 1];
		mergesort(mine[v][i - 1], mine[dp[v][i - 1]][i - 1], mine[v][i]);
	}
	for (int u : adj[v])
	{
		if (u != p)
		{
			dfs(u, v);
		}
	}
}
int get_par(int v, int k)
{
	for (int i = 0; i < MAX_L; i++)
	{
		if (k >> i & 1)
		{
			mergesort(mine[v][i], ans, komak);
			ans = komak;
			komak.clear();
			v = dp[v][i];
		}
	}
	return v;
}
int lca(int v, int u)
{
	if (dis[v] < dis[u])
	{
		swap(v, u);
	}
	v = get_par(v, dis[v] - dis[u]);
	if (u == v)
	{
		mergesort(ans, zen[v], komak);
		ans = komak;
		komak.clear();
		return v;
	}
	for (int i = MAX_L - 1; i >= 0; i--)
	{
		if (dp[v][i] != dp[u][i])
		{
			mergesort(mine[v][i], ans, komak);
			ans = komak;
			komak.clear();
			mergesort(mine[u][i], ans, komak);
			ans = komak;
			komak.clear();
			v = dp[v][i];
			u = dp[u][i];
		}
	}
	mergesort(zen[u], ans, komak);
	ans = komak;
	komak.clear();
	mergesort(zen[v], ans, komak);
	ans = komak;
	komak.clear();
	mergesort(zen[dp[v][0]], ans, komak);
	ans = komak;
	komak.clear();
	return dp[v][0];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	/*vector<int> o,l;
	o.pb(3);
	l.pb(2);
	mergesort(o,l,komak);
	ans=komak;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;*/
	cin >> n >> m >> q;
	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> a;
		zen[a].pb(i);
	}
	dfs(1, 0);
	/*for(int i=0;i<mine[5][1].size();i++){
		cout<<mine[5][1][i]<<" ";
	}
	return 0;*/
	int x, y, w;
	while (q--)
	{
		cin >> x >> y >> w;
		ans.clear();
		lca(x, y);
		int g = min(w, int(ans.size()));
		cout << g << " ";
		for (int i = 0; i < g; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
