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
int n, q, sq, a[MAX_N], l[MAX_N], r[MAX_N], so[MAX_N];
int ans[MAX_N], temp, s, e, cnt[MAX_N];
bool cmp(int x, int y)
{
	if (l[x] / sq < l[y] / sq)
		return 1;
	else if (l[x] / sq == l[y] / sq && r[x] < r[y])
		return 1;
	return 0;
}
void add(int x)
{
	if (a[x] > 1e5 || a[x] == 0)
		return;
	if (cnt[a[x]] == a[x])
		temp--;
	cnt[a[x]]++;
	if (cnt[a[x]] == a[x])
		temp++;
}
void del(int x)
{
	if (a[x] > 1e5 || a[x] == 0)
		return;
	if (cnt[a[x]] == a[x])
		temp--;
	cnt[a[x]]--;
	if (cnt[a[x]] == a[x])
		temp++;
}
void mo(int x, int y)
{
	if (e < y)
	{
		while (e < y)
		{
			e++;
			add(e);
		}
	}
	if (s > x)
	{
		while (s > x)
		{
			s--;
			add(s);
		}
	}
	if (e > y)
	{
		while (e > y)
		{
			del(e);
			e--;
		}
	}
	if (s < x)
	{
		while (s < x)
		{
			del(s);
			s++;
		}
	}
}
int main()
{
	scanf("%d %d", &n, &q);
	sq = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%d %d", &l[i], &r[i]);
		so[i] = i;
	}
	sort(so + 1, so + q + 1, cmp);
	for (int i = 1; i <= q; i++)
	{
		mo(l[so[i]], r[so[i]]);
		ans[so[i]] = temp;
	}
	for (int i = 1; i <= q; i++)
	{
		printf("%d\n", ans[i]);
	}
}
