/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, m;
vector<int> adj[MAX_N], tar;
int st[MAX_N], en[MAX_N], so[MAX_N], l[MAX_N], r[MAX_N], w[MAX_N], sq, an[MAX_N], t[MAX_N], col[MAX_N], cnt[MAX_N];
bool cmp(int x, int y)
{
	if (l[x] / sq < l[y] / sq || (l[x] / sq == l[y] / sq && r[x] < r[y]))
	{
		return 1;
	}
	return 0;
}
void add(int s)
{
	cnt[col[tar[s]]]++;
	t[cnt[col[tar[s]]]]++;
}
void del(int s)
{
	t[cnt[col[tar[s]]]]--;
	cnt[col[tar[s]]]--;
}
void update(int l2, int r2, int s, int e)
{
	if (l2 < s)
	{
		for (int j = s - 1; j >= l2; j--)
		{
			add(j);
		}
	}
	if (e < r2)
	{
		for (int j = e + 1; j <= r2; j++)
		{
			add(j);
		}
	}
	if (e > r2)
	{
		for (int j = e; j > r2; j--)
		{
			del(j);
		}
	}
	if (s < l2)
	{
		for (int j = s; j < l2; j++)
		{
			del(j);
		}
	}
}
void dfs(int v, int par)
{
	tar.pb(v);
	st[v] = tar.size() - 1;
	for (int u : adj[v])
	{
		if (u != par)
		{
			dfs(u, v);
		}
	}
	en[v] = tar.size() - 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	sq = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> col[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	tar.pb(0);
	dfs(1, 0);
	//	for(int i=1;i<=n;i++){
	//		cout<<st[i]<<" "<<en[i]<<endl;
	//	}
	//	for(int i=0;i<tar.size();i++){
	//		cout<<tar[i]<<" ";
	//	}
	for (int i = 1; i <= m; i++)
	{
		so[i] = i;
		int a, b;
		cin >> a >> b;
		l[i] = st[a];
		r[i] = en[a];
		w[i] = b;
	}
	//	cout<<l[1]<<"  "<<r[1];
	//	cout<<col[tar[2]];
	sort(so + 1, so + m + 1, cmp);
	int s = 0, e = 0;
	for (int i = 1; i <= m; i++)
	{
		update(l[so[i]], r[so[i]], s, e);
		s = l[so[i]];
		e = r[so[i]];
		an[so[i]] = t[w[so[i]]];
	}
	//	for(int i=0;i<=6;i++){
	//		cout<<cnt[i]<<" ";
	//	}
	for (int i = 1; i <= m; i++)
	{
		cout << an[i] << endl;
	}
}
