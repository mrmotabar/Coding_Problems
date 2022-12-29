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
ll dp[MAX_N], seg[4 * MAX_N], ans;
ll n, a[MAX_N], b[MAX_N], h[MAX_N], c[MAX_N], so[MAX_N];
bool cmp(int x, int y)
{
	if (b[x] != b[y])
		return b[x] < b[y];
	return a[x] < a[y];
}
void upd(int id, int b, int e, int p, ll val)
{
	if (p >= e || p < b)
		return;
	if (e - b == 1)
	{
		seg[id] = val;
		return;
	}
	int mid = (e + b) / 2;
	upd(id * 2, b, mid, p, val);
	upd(id * 2 + 1, mid, e, p, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
ll get(int id, int b, int e, int l, int r)
{
	if (l >= e || b >= r)
		return 0;
	if (l <= b && e <= r)
		return seg[id];
	int mid = (b + e) / 2;
	return max(get(id * 2, b, mid, l, r), get(id * 2 + 1, mid, e, l, r));
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
	for (int i = 1; i <= n; i++)
	{
		int ind = lower_bound(c + 1, c + n + 1, a[so[i]] + 1) - c;
		dp[i] = h[so[i]] + get(1, 1, n + 1, ind, n + 1);
		upd(1, 1, n + 1, i, dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
