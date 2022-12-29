/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 100 + 10, INF = 1e9;
ll p[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
ll dp[MAX_N][(1 << 17) + 2], bakhsh[60 + 10], n, a[MAX_N], pp[MAX_N][(1 << 17) + 2];
vector<ll> pans;
void print(ll j, ll i)
{
	pans.push_back(pp[j][i]);
	if (j == 0)
	{
		return;
	}
	print(j - 1, i ^ bakhsh[pp[j][i]]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i <= 60; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			if (i % p[j] == 0)
			{
				bakhsh[i] |= (1 << j);
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= (1 << 18) + 2; j++)
		{
			dp[i][j] = INF;
		}
	}
	for (int i = 1; i <= 60; i++)
	{
		if (abs(a[0] - i) < dp[0][bakhsh[i]])
		{
			dp[0][bakhsh[i]] = abs(a[0] - i);
			pp[0][bakhsh[i]] = i;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= 60; j++)
		{
			for (int k = 0; k <= (1 << 17); k++)
			{
				if ((k | bakhsh[j]) == k && dp[i - 1][k ^ bakhsh[j]] + abs(a[i] - j) < dp[i][k])
				{
					if (i == 4 && k == 2)
					{
						// cout<<j<<endl;
					}
					dp[i][k] = dp[i - 1][k ^ bakhsh[j]] + abs(a[i] - j);
					pp[i][k] = j;
				}
			}
		}
	}
	ll inan = 0;
	for (int i = 1; i < (1 << 17); i++)
	{
		if (dp[n - 1][i] < dp[n - 1][inan])
		{
			inan = i;
		}
	}
	// cout<<inan<<endl;
	print(n - 1, inan);
	for (int i = pans.size() - 1; i >= 0; i--)
	{
		cout << pans[i] << " ";
	}
}
