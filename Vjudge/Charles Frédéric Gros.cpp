#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX_N = 1000 * 10, INF = 99999;
string k[MAX_N];
int n, m;
int dp[MAX_N], depth[MAX_N], from[MAX_N], to[MAX_N];
bool vis[MAX_N], ans[MAX_N];
vector<int> adj[MAX_N];
vector<string> ci;
map<string, int> mp;
void dfs(int v, int de, int par)
{
	depth[v] = de;
	vis[v] = 1;
	dp[v] = INF;
	int ch = 0;
	for (int y : adj[v])
	{
		int b = from[y] ^ to[y] ^ v;
		if (y == par)
		{
			continue;
		}
		if (vis[b])
		{
			dp[v] = min(dp[v], depth[b]);
		}
		else
		{
			ch++;
			dfs(b, de + 1, y);
			dp[v] = min(dp[v], dp[b]);
			if (dp[b] >= depth[v])
			{
				ans[v] = 1;
			}
		}
	}
	if (ch < 2 && par == -1)
		ans[v] = 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 0;
	while (1)
	{
		cin >> n;
		t++;
		if (n == 0)
		{
			return 0;
		}
		if (t > 1)
		{
			cout << endl;
		}
		ci.clear();
		mp.clear();
		for (int i = 0; i <= n; i++)
		{
			vis[i] = 0;
			adj[i].clear();
			ans[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> k[i];
			mp[k[i]] = i;
		}
		cin >> m;
		string s1, s2;
		for (int i = 0; i < m; i++)
		{
			cin >> s1 >> s2;
			from[i] = mp[s1];
			to[i] = mp[s2];
			adj[from[i]].push_back(i);
			adj[to[i]].push_back(i);
		}
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				dfs(i, 0, -1);
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (ans[i])
			{
				ci.push_back(k[i]);
			}
		}
		cout << "City map #" << t << ": " << ci.size() << " camera(s) found" << endl;
		sort(ci.begin(), ci.end());
		for (string i : ci)
		{
			cout << i << endl;
		}
	}
}
