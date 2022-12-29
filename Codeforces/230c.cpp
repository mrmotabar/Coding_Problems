/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int n, m, ans = INF;
char c[100 + 10][10000 + 100];
vector<int> bit[100 + 10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == '1')
			{
				bit[i].pb(j);
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			int a = lower_bound(bit[j].begin(), bit[j].end(), i) - bit[j].begin();
			if (bit[j].size() == 0)
			{
				cout << -1;
				return 0;
			}
			int b = min(abs(i - bit[j][0]), abs(m - i + bit[j][0]));
			int c = min(abs(bit[j][bit[j].size() - 1] - i), abs(m + i - bit[j][bit[j].size() - 1]));
			int d = INF, e = INF;
			if (lower_bound(bit[j].begin(), bit[j].end(), i) != bit[j].end())
			{
				d = min(abs(i - bit[j][a]), abs(m - i + bit[j][a]));
				if (a > 0)
				{
					e = min(abs(i - bit[j][a - 1]), abs(m - i + bit[j][a - 1]));
				}
			}
			sum += min(min(b, c), min(d, e));
		}
		ans = min(ans, sum);
	}
	cout << ans;
}
