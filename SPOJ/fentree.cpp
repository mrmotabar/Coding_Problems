/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e6 + 10, INF = 1e9;
ll n, q, a[MAX_N], fen[MAX_N];
void add(int x, int val)
{
	for (; x <= n; x += (x & (-1 * x)))
	{
		fen[x] += val;
	}
}
ll get(int x)
{
	ll ret = 0;
	for (; x; x -= (x & (-1 * x)))
	{
		ret += fen[x];
	}
	return ret;
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
		add(i, a[i]);
	}
	cin >> q;
	while (q--)
	{
		int l, r;
		char x;
		cin >> x >> l >> r;
		if (x == 'q')
			cout << get(r) - get(l - 1) << endl;
		else
			add(l, r);
	}
}
