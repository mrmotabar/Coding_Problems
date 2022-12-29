/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 3e5, INF = 1e9;
int n, d[MAX_N], w[MAX_N], ans;
vector<int> s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i] >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		while (s.size())
		{
			if (w[i] < s[int(s.size()) - 1])
			{
				s.pop_back();
			}
			else
			{
				break;
			}
		}
		if (s.size() && s[int(s.size()) - 1] == w[i])
		{
		}
		else
		{
			ans++;
		}
		s.pb(w[i]);
	}
	cout << ans;
}
