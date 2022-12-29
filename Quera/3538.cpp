/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int a[7 + 10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	for (int i = 0; i < 3; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> s;
			if (s[0] == 's')
			{
				a[0]++;
			}
			else if (s[0] == 'j')
			{
				a[6]++;
			}
			else
			{
				a[s[0] - '0']++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 7; i++)
	{
		if (a[i] == 0)
		{
			ans++;
		}
	}
	cout << ans;
}
