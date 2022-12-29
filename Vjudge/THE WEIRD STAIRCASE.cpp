#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int max_n = 200000;
const int bina = 9000000;
vector<int> adj[max_n];
int a[max_n];
int d[max_n];
int q[max_n];
int main()
{
	int n, t;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		cin >> n;
		for (int i = 0; i <= n; i++)
		{
			adj[i].clear();
			d[i] = bina;
			q[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] + i >= 0 && a[i] + i <= n)
			{
				adj[i].push_back(a[i] + i);
			}
			adj[i].push_back(i + 1);
		}
		int h = 0, t = 0;
		d[0] = 0;
		q[t++] = 0;
		while (h < t)
		{
			int v = q[h++];
			for (int u : adj[v])
			{
				if (d[v] + 1 < d[u])
				{
					d[u] = d[v] + 1;
					q[t++] = u;
				}
			}
		}
		cout << d[n] << endl;
	}
}
