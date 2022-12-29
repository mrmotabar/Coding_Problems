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
int n, p[MAX_N], ans, en;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	p[0] = p[1];
	ans = p[0];
	for (int i = 1; i < n; i++)
	{
		if (en + (p[i] - p[i + 1]) < 0)
		{
			ans += abs(en + (p[i] - p[i + 1]));
			en = 0;
		}
		else
			en += (p[i] - p[i + 1]);
	}
	cout << ans << endl;
}
