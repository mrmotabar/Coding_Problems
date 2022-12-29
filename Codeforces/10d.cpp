/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
pair<ll, ll> dp[500 + 100][500 + 100], up[500 + 100][500 + 100];
ll a[500 + 100], b[500 + 100], n, m;
void pp(ll i, ll j)
{
	if (i == 0 && j == 0)
	{
		return;
	}
	if (up[i][j].first == -1 && up[i][j].second == -1)
	{
		cout << a[i] << " ";
	}
	else if (up[i][j].first != i - 1 || up[i][j].second != j - 1)
	{
		pp(up[i][j].first, up[i][j].second);
	}
	else
	{
		pp(up[i][j].first, up[i][j].second);
		cout << a[i] << " ";
	}
}
string scon(ll i)
{
	if (i == 0)
	{
		return "0";
	}
	string s, q;
	int z = i;
	while (z > 0)
	{
		s += char(int('0') + z % 10);
		z /= 10;
	}
	for (int j = 0; j < s.size(); j++)
	{
		q += s[s.size() - j - 1];
	}
	return q;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			dp[i][j].second = -1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			{
				if (dp[i - 1][j - 1].second < a[i])
				{
					dp[i][j].first = dp[i - 1][j - 1].first + 1;
					dp[i][j].second = a[i];
					up[i][j] = {i - 1, j - 1};
				}
				else if (dp[i - 1][j - 1].first == 1 && dp[i - 1][j - 1].second > a[i])
				{
					dp[i][j].first = 1;
					dp[i][j].second = a[i];
					up[i][j] = {-1, -1};
				}
				else
				{
					dp[i][j].first = max(dp[i - 1][j].first, dp[i][j - 1].first);
					bool l2 = false;
					if (dp[i][j].first == dp[i - 1][j].first)
					{
						dp[i][j].second = dp[i - 1][j].second;
						up[i][j] = {i - 1, j};
						l2 = true;
					}
					if (dp[i][j].first == dp[i][j - 1].first)
					{
						dp[i][j].second = min(dp[i][j].second, dp[i][j - 1].second);
						if (l2)
							dp[i][j].second = min(dp[i][j].second, dp[i][j - 1].second);
						else
							dp[i][j].second = dp[i][j - 1].second;
						if (dp[i][j].second == dp[i][j - 1].second)
						{
							up[i][j] = {i, j - 1};
						}
					}
				}
			}
			else
			{
				dp[i][j].first = max(dp[i - 1][j].first, dp[i][j - 1].first);
				bool l = false;
				if (dp[i][j].first == dp[i - 1][j].first)
				{
					dp[i][j].second = dp[i - 1][j].second;
					up[i][j] = {i - 1, j};
					l = true;
				}
				if (dp[i][j].first == dp[i][j - 1].first)
				{
					if (l)
						dp[i][j].second = min(dp[i][j].second, dp[i][j - 1].second);
					else
						dp[i][j].second = dp[i][j - 1].second;
					if (dp[i][j].second == dp[i][j - 1].second)
					{
						up[i][j] = {i, j - 1};
					}
				}
			}
		}
	}
	/*	for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<dp[i][j].second<<"  ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<up[i][j].first<<"|"<<up[i][j].second<<"   ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;*/
	cout << dp[n][m].first << endl;
	pp(n, m);
}
