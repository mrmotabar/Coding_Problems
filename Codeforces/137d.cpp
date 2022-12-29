/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
ll cnt[500 + 100][500 + 100], cp[500 + 100][500 + 100], dp[500 + 100][500 + 100], dpp[500 + 100][500 + 100], n;
string s, ans;
void cpp(int x, int y, int h)
{
	if (h == 0)
	{
		return;
	}
	if (s[x] != s[y])
	{
		s[x] = s[y];
		cpp(x + 1, y - 1, h - 1);
	}
	else
	{
		cpp(x + 1, y - 1, h);
	}
}
void pp(int x, int y)
{
	if (y == 0)
	{
		return;
	}
	if (cp[dpp[x][y] + 1][x] > 0)
	{
		cpp(dpp[x][y] + 1, x, cp[dpp[x][y] + 1][x]);
	}
	pp(dpp[x][y], y - 1);
	for (int i = dpp[x][y] + 1; i <= x; i++)
	{
		ans += s[i];
	}
	ans += '+';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> n;
	for (int i = 0; i < s.size() + 5; i++)
	{
		for (int j = 0; j < n + 10; j++)
		{
			dp[i][j] = INF;
		}
	}
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			cnt[i][i + 1] = 0;
			cp[i][i + 1] = 0;
		}
		else
		{
			cnt[i][i + 1] = 1;
			cp[i][i + 1] = 1;
		}
	}
	for (int i = s.size() - 2; i >= 0; i--)
	{
		for (int j = i + 2; j < s.size(); j++)
		{
			cnt[i][j] = cnt[i + 1][j - 1];
			cp[i][j] = cp[i + 1][j - 1];
			if (s[i] != s[j])
			{
				cnt[i][j]++;
				cp[i][j]++;
			}
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		dp[i][1] = cnt[0][i];
		dpp[i][1] = -1;
	}
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 2; j <= n; j++)
		{
			for (int k = 0; k < i; k++)
			{
				if (dp[k][j - 1] + cnt[k + 1][i] < dp[i][j])
				{
					dp[i][j] = dp[k][j - 1] + cnt[k + 1][i];
					dpp[i][j] = k;
				}
			}
		}
	}
	int inan = 1;
	for (int i = 2; i <= n; i++)
	{
		if (dp[s.size() - 1][i] < dp[s.size() - 1][inan])
		{
			inan = i;
		}
	}
	cout << dp[s.size() - 1][inan] << endl;
	pp(s.size() - 1, inan);
	for (int i = 0; i < ans.size() - 1; i++)
	{
		cout << ans[i];
	}
}
