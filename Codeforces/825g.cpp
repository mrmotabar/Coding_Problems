/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAX_N = 3e6 + 10;
int n, q, minn[MAX_N], root, last = 0, ans = (1 << 120), x;
vector<int> adj[MAX_N];
void dfs(int v, int p = 0, int val = root)
{
	minn[v] = min(v, minn[p]);
	for (int u : adj[v])
	{
		if (u != p)
			dfs(u, v, minn[v]);
	}
}
int main()
{
	memset(minn, 63, sizeof minn);
	scanf("%d %d", &n, &q);
	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	scanf("%d %d", &a, &b);
	root = (b + last) % n + 1;
	q--;
	ans = root;
	dfs(root);
	while (q--)
	{
		scanf("%d %d", &a, &b);
		b = (b + last) % n + 1;
		if (a == 1)
			ans = min(ans, minn[b]);
		else
		{
			x = min(ans, minn[b]);
			printf("%d\n", x);
			last = x;
		}
	}
}
