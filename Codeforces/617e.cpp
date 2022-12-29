/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 2e6 + 10, INF = 1e12;
ll n, m, k, a[MAX_N], l[MAX_N], r[MAX_N], so[MAX_N], an[MAX_N], cnt[MAX_N], ans, sq, pxo[MAX_N];
bool cmp(int x, int y)
{
	if (l[x] / sq < l[y] / sq || (l[x] / sq == l[y] / sq && r[x] < r[y]))
	{
		return 1;
	}
	return 0;
}
void del(int s)
{
	if (pxo[s] <= 2e6)
	{
		cnt[pxo[s]]--;
	}
	if ((pxo[s] ^ k) <= 2e6)
	{
		ans -= cnt[pxo[s] ^ k];
	}
}
void add(int s)
{
	if ((pxo[s] ^ k) <= 2e6)
	{
		ans += cnt[pxo[s] ^ k];
	}
	if (pxo[s] <= 2e6)
	{
		cnt[pxo[s]]++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	sq = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pxo[i] = pxo[i - 1] ^ a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> l[i] >> r[i];
		so[i] = i;
	}
	sort(so + 1, so + m + 1, cmp);
	ll s = 0, e = 0;
	cnt[0]++;
	for (int i = 1; i <= m; i++)
	{
		if (s < l[so[i]])
		{
			while (e < r[so[i]])
			{
				e++;
				add(e);
			}
			while (e > r[so[i]])
			{
				del(e);
				e--;
			}
			while (s < l[so[i]] - 1)
			{
				del(s);
				s++;
			}
		}
		else
		{
			while (s > l[so[i]] - 1)
			{
				s--;
				add(s);
			}
			while (e < r[so[i]])
			{
				e++;
				add(e);
			}
			while (e > r[so[i]])
			{
				del(e);
				e--;
			}
		}
		an[so[i]] = ans;
	}
	for (ll i = 1; i <= m; i++)
	{
		cout << an[i] << endl;
	}
}
