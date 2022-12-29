/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
string s, ans[100];
int n;
bool c = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	ans[0] = s;
	while (n < s.size())
	{
		for (int i = 0; i <= n; i++)
		{
			s[i] = s[n + 1];
		}
		ans[n + 1] = s;
		n++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << endl;
	}
}
