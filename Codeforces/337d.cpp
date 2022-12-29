#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 1000 * 1000 + 100;
int d, n, m;
bool boomb[MAX_N];
vector<int> adj[MAX_N];
int dp11[MAX_N], dp12[MAX_N];
void dfsdown(int v, int l)
{
	for (int u : adj[v])
	{
		if (u == l)
		{
			continue;
		}
		dfsdown(u, v);
		if (dp11[v] < dp11[u] + 1)
		{
			dp12[v] = dp11[v];
			dp11[v] = dp11[u] + 1;
		}
		else if (dp12[v] < dp11[u] + 1)
		{
			dp12[v] = dp11[u] + 1;
		}
	}
}
bool dfsup(int v, int l)
{
	if (v != 1)
	{
		int x = 0;
		if (dp11[l] == dp11[v] + 1)
		{
			x = dp12[l] + 1;
		}
		else
		{
			x = dp11[l] + 1;
		}
		if (x > dp11[v])
		{
			dp12[v] = dp11[v];
			dp11[v] = x;
		}
		else if (x > dp12[v])
		{
			dp12[v] = x;
		}
	}
	for (int u : adj[v])
	{
		if (u != l)
			dfsup(u, v);
	}
}
int main()
{
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		boomb[a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		dp11[i] = -999999;
		dp12[i] = -999999;
		if (boomb[i])
		{
			dp11[i] = 0;
			dp12[i] = 0;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfsdown(1, 0);
	dfsup(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dp11[i] <= d)
		{
			ans++;
			// cout<<i<<endl;
		}
		//	cout<<dp11[i]<<"  "<<dp12[i]<<endl;
	}
	cout << ans;
}
