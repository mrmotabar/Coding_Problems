/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 100, INF = 1e9;
ll w[MAX_N], sor[MAX_N], from[MAX_N], to[MAX_N], n, m, par[MAX_N], ans;
bool mst[MAX_N];
int get_root(int v)
{
	return (par[v] == v ? v : par[v] = get_root(par[v]));
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
bool cmp(int x, int y)
{
	if (w[x] < w[y])
	{
		return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		w[i] = c;
		from[i] = a;
		to[i] = b;
	}
	for (int i = 0; i < n + 2; i++)
	{
		par[i] = i;
	}
	for (int i = 0; i < m + 2; i++)
	{
		sor[i] = i;
	}
	sort(sor, sor + m, cmp);
	for (int i = 0; i < m; i++)
	{
		if (get_root(from[sor[i]]) != get_root(to[sor[i]]))
		{
			merge(from[sor[i]], to[sor[i]]);
			mst[sor[i]] = 1;
			ans += w[sor[i]];
		}
	}
	cout << ans;
}
