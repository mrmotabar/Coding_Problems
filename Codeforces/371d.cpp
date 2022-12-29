/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 2e5 + 10, INF = 1e9;
ll n, a[MAX_N], b[MAX_N], q;
ll pes[MAX_N];
ll get_root(int v, int wat)
{
	if (a[v] - b[v] > wat)
	{
		b[v] += wat;
		return pes[v] = v;
	}
	else if (a[v] - b[v] == wat)
	{
		b[v] = a[v];
		return pes[v] = pes[v + 1];
	}
	else if (a[v] - b[v] < wat)
	{
		wat -= abs(a[v] - b[v]);
		b[v] = a[v];
		return pes[v] = get_root(pes[v + 1], wat);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n + 1; i++)
	{
		pes[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	a[n + 1] = INF * INF;
	cin >> q;
	int x, z, w;
	while (q--)
	{
		cin >> x;
		if (x == 1)
		{
			cin >> z >> w;
			get_root(z, w);
		}
		else
		{
			cin >> z;
			cout << b[z] << endl;
		}
	}
}
