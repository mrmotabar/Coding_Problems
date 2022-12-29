/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, ans;
vector<int> of[MAX_N], am[MAX_N];
int x[MAX_N], y[MAX_N];
unordered_map<int, bool> hast[MAX_N];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		hast[x[i]][y[i]] = 1;
		of[y[i]].pb(x[i]);
		am[x[i]].pb(y[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (of[y[i]].size() > am[x[i]].size())
		{
			for (int j = 0; j < am[x[i]].size(); j++)
			{
				if (am[x[i]][j] < y[i])
				{
					int zel = y[i] - am[x[i]][j];
					if (hast[x[i] + zel].count(y[i]) > 0 && hast[x[i] + zel].count(y[i] - zel) > 0)
						if (hast[x[i] + zel][y[i]] && hast[x[i] + zel][y[i] - zel])
							ans++;
				}
			}
		}
		else
		{
			for (int j = 0; j < of[y[i]].size(); j++)
			{
				if (of[y[i]][j] > x[i])
				{
					int zel = of[y[i]][j] - x[i];
					if (hast[x[i]].count(y[i] - zel) > 0 && hast[x[i] + zel].count(y[i] - zel) > 0)
						if (hast[x[i]][y[i] - zel] && hast[x[i] + zel][y[i] - zel])
							ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
}
