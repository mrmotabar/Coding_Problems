/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 10, INF = 1e9;
ll n, m, a[MAX_N], l[MAX_N], r[MAX_N], sq, cnt[MAX_N], ans, so[MAX_N], an[MAX_N];
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
	ans -= 2 * cnt[a[s]] * a[s];
	ans += a[s];
	cnt[a[s]]--;
}
void add(int s)
{
	ans += 2 * cnt[a[s]] * a[s];
	ans += a[s];
	cnt[a[s]]++;
}
int main()
{
	cin >> n >> m;
	sq = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		so[i] = i;
		scanf("%lld %lld", &l[i], &r[i]);
	}
	sort(so + 1, so + m + 1, cmp);
	int s = 0, e = 0;
	for (int i = 1; i <= m; i++)
	{
		if (s <= l[so[i]])
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
			while (s < l[so[i]])
			{
				del(s);
				s++;
			}
		}
		else
		{
			while (s > l[so[i]])
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
	for (int i = 1; i <= m; i++)
	{
		printf("%lld\n", an[i]);
		// cout<<cnt[i]<<endl;
	}
}
