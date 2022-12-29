/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, m, a[MAX_N], l[MAX_N], r[MAX_N], sq, cnt[MAX_N], ans, so[MAX_N], an[MAX_N];
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
	if (a[s] > 1e5)
	{
		return;
	}
	if (cnt[a[s]] == a[s])
	{
		ans--;
	}
	cnt[a[s]]--;
	if (cnt[a[s]] == a[s])
	{
		ans++;
	}
}
void add(int s)
{
	if (a[s] > 1e5)
	{
		return;
	}
	if (cnt[a[s]] == a[s])
	{
		ans--;
	}
	cnt[a[s]]++;
	if (cnt[a[s]] == a[s])
	{
		ans++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	sq = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		so[i] = i;
		cin >> l[i] >> r[i];
	}
	sort(so + 1, so + m + 1, cmp);
	int s = 1, e = 1;
	if (a[1] <= 1e5)
	{
		cnt[a[1]]++;
	}
	if (a[1] == 1)
	{
		ans++;
	}
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
		cout << an[i] << endl;
	}
}
