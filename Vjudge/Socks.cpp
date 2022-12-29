#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<int> adj[1000000];
int vis[2000000 + 10];
int co[1000000];
int y = 0;
map<int, int> mp[200000 + 10];
void dfs(int v)
{
	vis[v] = 1;
	mp[y][co[v]]++;
	for (int u : adj[v])
	{
		if (!vis[u])
		{
			dfs(u);
		}
	}
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> co[i];
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	// cout<<adj[2].size();
	// for(int i=0;i<adj[2].size();i++){
	//	cout<<adj[3][i]<<" ";
	// }
	// return 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0 && adj[i].size() > 0)
		{
			dfs(i);
			y++;
			int sum = 0, max = 0;
			for (pair<int, int> u : mp[y - 1])
			{
				sum += u.second;
				if (u.second > max)
				{
					max = u.second;
				}
			}
			ans += sum - max;
		}
	}
	cout << ans;
}
