/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 2000 + 100, INF = 1e9;
vector<int> doos[MAX_N];
ll par[MAX_N];
bool no[MAX_N], vis[MAX_N];
ll n, m, k, ans, c;
int get_root(int v)
{
	return (par[v] == -1 ? v : par[v] = get_root(par[v]));
}
void merge(int v, int u)
{
	int pv = get_root(v);
	int pu = get_root(u);
	if (pv == pu)
	{
		return;
	}
	par[pu] = pv;
}
void dfs(int v)
{
	vis[v] = 1;
	c++;
	for (int u : doos[v])
	{
		if (!vis[u])
		{
			dfs(u);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		doos[a].push_back(b);
		doos[b].push_back(a);
		merge(a, b);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (get_root(a) == get_root(b))
		{
			no[get_root(a)] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && par[i] == -1 && !no[i])
		{
			c = 0;
			dfs(i);
			ans = max(ans, c);
			// cout<<i<<"  "<<c<<endl;
		}
	}
	cout << ans;
}
