/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const int MAX_N = 1e5 + 10, INF = 1e9, sq = sqrt(1e5);
int n, m, a[MAX_N];
pii ans[MAX_N];
void build()
{
	for (int i = 1; i <= n; i += sq)
	{
		for (int j = min(i + sq - 1, n); j >= i; j--)
		{
			if (j + a[j] >= min(i + sq, n + 1))
			{
				ans[j] = {j, 1};
			}
			else
			{
				ans[j] = {ans[j + a[j]].F, ans[j + a[j]].S + 1};
			}
		}
	}
}
void upd(int v, int val)
{
	a[v] = val;
	for (int i = v; i > v - (v % sq); i--)
	{
		if (i + a[i] >= min(v - (v % sq) + sq, n + 1))
		{
			ans[i] = {i, 1};
		}
		else
		{
			ans[i] = {ans[i + a[i]].F, ans[i + a[i]].S + 1};
		}
	}
}
pii get(int v)
{
	if (ans[v].F + a[ans[v].F] > n)
	{
		return ans[v];
	}
	pii u = get(ans[v].F + a[ans[v].F]);
	return {u.F, u.S + ans[v].S};
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	build();
	while (m--)
	{
		int x, y, z;
		scanf("%d", &x);
		if (!x)
		{
			scanf("%d %d", &y, &z);
			upd(y, z);
		}
		else
		{
			scanf("%d", &y);
			pii x = get(y);
			printf("%d %d\n", x.F, x.S);
		}
	}
}
