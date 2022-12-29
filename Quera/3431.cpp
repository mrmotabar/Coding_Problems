/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 50 + 50, INF = 1e9;
int n, m, ans;
char c[MAX_N][MAX_N];
string s;
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
		}
	}
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < s.size(); k++)
			{
				if (s[k] != c[i][j + k] || j + k >= m)
					break;
				if (k == s.size() - 1)
					ans++;
			}
			for (int k = 0; k < s.size(); k++)
			{
				if (s[k] != c[i + k][j] || i + k >= n)
					break;
				if (k == s.size() - 1)
					ans++;
			}
		}
	}
	cout << ans << endl;
}
