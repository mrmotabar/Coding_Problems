/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 5e5 + 10, INF = 1e9;
int n, q, st[MAX_N], fi[MAX_N];
int fil[4 * MAX_N], empty[4 * MAX_N];
vector<int> adj[MAX_N], stfi;
void dfs(int v, int par = 0)
{
	stfi.pb(v);
	st[v] = stfi.size();
	for (int u : adj[v])
	{
		if (u != par)
		{
			dfs(u, v);
		}
	}
	fi[v] = stfi.size();
}
void updfill(int id, int b, int e, int s, int f, int time)
{
	if (s >= e || b >= f)
		return;
	if (s <= b && e <= f)
	{
		fil[id] = time;
		return;
	}
	int mid = (e + b) / 2;
	updfill(id * 2, b, mid, s, f, time);
	updfill(id * 2 + 1, mid, e, s, f, time);
}
int getfill(int id, int b, int e, int s)
{
	if (s < b || s >= e)
		return 0;
	if (e - b == 1)
		return fil[id];
	int mid = (e + b) / 2;
	return max(max(getfill(id * 2, b, mid, s), getfill(id * 2 + 1, mid, e, s)), fil[id]);
}
void updempty(int id, int b, int e, int s, int time)
{
	if (s < b || s >= e)
		return;
	if (e - b == 1)
	{
		empty[id] = time;
		return;
	}
	int mid = (e + b) / 2;
	updempty(id * 2, b, mid, s, time);
	updempty(id * 2 + 1, mid, e, s, time);
	empty[id] = max(empty[id * 2], empty[id * 2 + 1]);
}
int getempty(int id, int b, int e, int s, int f)
{
	if (s >= e || b >= f)
		return 0;
	if (s <= b && e <= f)
		return empty[id];
	int mid = (b + e) / 2;
	return max(getempty(id * 2, b, mid, s, f), getempty(id * 2 + 1, mid, e, s, f));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1);
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1)
		{
			updfill(1, 1, n + 1, st[b], fi[b] + 1, i);
		}
		else if (a == 2)
		{
			updempty(1, 1, n + 1, st[b], i);
		}
		else
		{
			if (getfill(1, 1, n + 1, st[b]) > getempty(1, 1, n + 1, st[b], fi[b] + 1))
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
}
