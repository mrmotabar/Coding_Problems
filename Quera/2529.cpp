/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int n, ans, a[26 + 10];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		memset(a, 0, sizeof a);
		int t = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (!a[s[j] - 'a'])
			{
				t++;
			}
			a[s[j] - 'a']++;
		}
		ans = max(ans, t);
	}
	cout << ans;
}
