#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int sq = 710, MAX_N = 5e5 + 10, INF = 1e9 + 10;
;
int n, q, a[MAX_N], s[sq], e[sq], lazy[sq];
set<pair<int, int>> st[sq];
void add(int &a, int b)
{
	a = min(a + b, INF);
}
void get_input()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void prep()
{
	int ind = 0;
	for (int i = 0; i < n; i += sq)
	{
		s[ind] = i;
		e[ind] = min(i + sq, n) - 1;
		for (int j = s[ind]; j <= e[ind]; j++)
		{
			st[ind].insert({a[j], j});
		}
		ind++;
	}
}
void upd(int l, int r, int x)
{
	if (l / sq == r / sq)
	{
		for (int i = l; i <= r; i++)
		{
			st[i / sq].erase({a[i], i});
			add(a[i], x);
			st[i / sq].insert({a[i], i});
		}
		return;
	}
	for (int i = (l / sq) + 1; e[i] < r; i++)
	{
		add(lazy[i], x);
	}
	for (int i = l; i <= e[l / sq]; i++)
	{
		st[i / sq].erase({a[i], i});
		add(a[i], x);
		st[i / sq].insert({a[i], i});
	}
	for (int i = r; i >= s[r / sq]; i--)
	{
		st[i / sq].erase({a[i], i});
		add(a[i], x);
		st[i / sq].insert({a[i], i});
	}
}
int get(int y)
{
	int first = n, last = -1;
	for (int i = 0; i <= (n - 1) / sq; i++)
	{
		auto ind = st[i].lower_bound({y - lazy[i], 0});
		if ((*ind).F == y - lazy[i])
		{
			first = (*ind).S;
			break;
		}
	}
	for (int i = (n - 1) / sq; i >= 0; i--)
	{
		auto ind = st[i].upper_bound({y - lazy[i], n});
		ind--;
		if ((*ind).F == y - lazy[i])
		{
			last = (*ind).S;
			break;
		}
	}
	if (first == n)
	{
		return -1;
	}
	return last - first;
}
void answer()
{
	for (int i = 0; i < q; i++)
	{
		int noe;
		cin >> noe;
		if (noe == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			upd(l - 1, r - 1, x);
		}
		else
		{
			int y;
			cin >> y;
			cout << get(y) << endl;
		}
	}
}
int main()
{
	get_input();
	prep();
	answer();
}
