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
ll dp[MAX_N], fen[MAX_N], ans;
ll n, a[MAX_N], b[MAX_N], h[MAX_N], c[MAX_N], so[MAX_N];
bool cmp(int x, int y)
{
	if (b[x] != b[y])
		return b[x] < b[y];
	return a[x] < a[y];
}
ll get(int x)
{
	ll ret = 0;
	for (; x; x -= (x & -x))
	{
		ret = max(ret, fen[x]);
	}
	return ret;
}
void add(int x, ll val)
{
	for (; x <= n; x += (x & -x))
	{
		fen[x] = max(fen[x], val);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> h[i];
		so[i] = i;
	}
	sort(so + 1, so + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		c[i] = b[so[i]];
	}
	dp[1] = h[so[1]];
	ans = dp[1];
	add(n, dp[1]);
	for (int i = 2; i <= n; i++)
	{
		int ind = lower_bound(c + 1, c + n + 1, a[so[i]] + 1) - c;
		dp[i] = h[so[i]] + get(n - ind + 1);
		add(n - i + 1, dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
