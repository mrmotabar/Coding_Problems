/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e6, INF = 1e9;
ll t, n, m, a[MAX_N];
pll qyek[4 * MAX_N], layek[4 * MAX_N], qdo[4 * MAX_N], amf[MAX_N];
pair<int, pair<int, int>> lado[4 * MAX_N];
pll amel(ll x)
{
	ll amdo = 0, ampan = 0;
	ll ada = x;
	while (ada % 2 == 0)
	{
		amdo++;
		ada /= 2;
	}
	ada = x;
	while (ada % 5 == 0)
	{
		ampan++;
		ada /= 5;
	}
	return {amdo, ampan};
}
void builddo(ll id, ll b, ll e)
{
	if (e - b == 1)
	{
		pll val = amel(a[b]);
		qdo[id].first = val.first;
		qdo[id].second = val.second;
		return;
	}
	ll mid = (b + e) / 2;
	builddo(id * 2, b, mid);
	builddo(id * 2 + 1, mid, e);
	qdo[id].first = qdo[id * 2].first + qdo[id * 2 + 1].first;
	qdo[id].second = qdo[id * 2].second + qdo[id * 2 + 1].second;
}
void shiftyek(ll id, ll b, ll e)
{
	ll mid = (b + e) / 2;
	if (layek[id].first == -1 && layek[id].second == -1)
	{
		qyek[id * 2] = {0, 0};
		layek[id * 2] = {-1, -1};
		qyek[id * 2 + 1] = {0, 0};
		layek[id * 2 + 1] = {-1, -1};
		layek[id] = {0, 0};
		return;
	}
	if (layek[id * 2].first == -1 && layek[id * 2].second == -1)
	{
		shiftyek(id * 2, b, mid);
	}
	if (layek[id * 2 + 1].first == -1 && layek[id * 2 + 1].second == -1)
	{
		shiftyek(id * 2 + 1, mid, e);
	}
	qyek[id * 2].first += (mid - b) * layek[id].first;
	qyek[id * 2].second += (mid - b) * layek[id].second;
	layek[id * 2].first += layek[id].first;
	layek[id * 2].second += layek[id].second;

	qyek[id * 2 + 1].first += (e - mid) * layek[id].first;
	qyek[id * 2 + 1].second += (e - mid) * layek[id].second;
	layek[id * 2 + 1].first += layek[id].first;
	layek[id * 2 + 1].second += layek[id].second;

	layek[id] = {0, 0};
}
void shiftdo(ll id, ll b, ll e)
{
	if (lado[id].first == 0)
		return;
	ll mid = (b + e) / 2;
	qdo[id * 2].first = (mid - b) * lado[id].second.first + amf[(mid - b - 1) + lado[id].first].first - amf[lado[id].first - 1].first;
	qdo[id * 2].second = (mid - b) * lado[id].second.second + amf[(mid - b - 1) + lado[id].first].second - amf[lado[id].first - 1].second;
	lado[id * 2] = lado[id];

	qdo[id * 2 + 1].first = (e - mid) * lado[id].second.first + amf[(e - b - 1) + lado[id].first].first - amf[(mid - b - 1) + lado[id].first].first;
	qdo[id * 2 + 1].second = (e - mid) * lado[id].second.second + amf[(e - b - 1) + lado[id].first].second - amf[(mid - b - 1) + lado[id].first].second;
	lado[id * 2 + 1] = lado[id];
	lado[id * 2 + 1].first = (mid - b) + lado[id].first;

	lado[id] = {0, {0, 0}};
}
void updyek(ll id, ll b, ll e, ll l, ll r, pll val)
{
	if (l >= e || b >= r)
		return;
	if (l <= b && e <= r)
	{
		if (val.first == -1 && val.second == -1)
		{
			qyek[id] = {0, 0};
			layek[id] = {-1, -1};
			return;
		}
		shiftyek(id, b, e);
		shiftdo(id, b, e);
		qyek[id].first += (e - b) * val.first;
		qyek[id].second += (e - b) * val.second;
		layek[id].first += val.first;
		layek[id].second += val.second;
		return;
	}
	ll mid = (b + e) / 2;
	shiftyek(id, b, e);
	shiftdo(id, b, e);
	updyek(id * 2, b, mid, l, r, val);
	updyek(id * 2 + 1, mid, e, l, r, val);
	qyek[id].first = qyek[id * 2].first + qyek[id * 2 + 1].first;
	qyek[id].second = qyek[id * 2].second + qyek[id * 2 + 1].second;
}
void upddo(ll id, ll b, ll e, ll l, ll r, pll val)
{
	if (l >= e || b >= r)
		return;
	if (l <= b && e <= r)
	{
		qdo[id].first = (e - b) * val.first + amf[e - l].first - amf[b - l].first;
		qdo[id].second = (e - b) * val.second + amf[e - l].second - amf[b - l].second;
		lado[id].first = b - l + 1;
		lado[id].second.first = val.first;
		lado[id].second.second = val.second;
		return;
	}
	ll mid = (b + e) / 2;
	shiftdo(id, b, e);
	shiftyek(id, b, e);
	upddo(id * 2, b, mid, l, r, val);
	upddo(id * 2 + 1, mid, e, l, r, val);
	qdo[id].first = qdo[id * 2].first + qdo[id * 2 + 1].first;
	qdo[id].second = qdo[id * 2].second + qdo[id * 2 + 1].second;
}
pll get(ll id, ll b, ll e, ll l, ll r)
{
	if (l >= e || b >= r)
		return {0, 0};
	if (l <= b && e <= r)
	{
		ll doo = qdo[id].first + qyek[id].first;
		ll pan = qdo[id].second + qyek[id].second;
		return {doo, pan};
	}
	ll mid = (b + e) / 2;
	shiftyek(id, b, e);
	shiftdo(id, b, e);
	pll x = get(id * 2, b, mid, l, r);
	pll y = get(id * 2 + 1, mid, e, l, r);
	return {x.first + y.first, x.second + y.second};
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (ll i = 1; i <= 1e5; i++)
	{
		pll val = amel(i);
		amf[i].first = amf[i - 1].first + val.first;
		amf[i].second = amf[i - 1].second + val.second;
	}
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		ll ans = 0;
		memset(qyek, 0, sizeof qyek);
		memset(qdo, 0, sizeof qdo);
		memset(layek, 0, sizeof layek);
		memset(lado, 0, sizeof lado);
		for (ll i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		builddo(1, 1, n + 1);
		ll noe, l, r, x;
		while (m--)
		{
			cin >> noe;
			if (noe == 1)
			{
				cin >> l >> r >> x;
				updyek(1, 1, n + 1, l, r + 1, amel(x));
			}
			else if (noe == 2)
			{
				cin >> l >> r >> x;
				upddo(1, 1, n + 1, l, r + 1, amel(x));
				updyek(1, 1, n + 1, l, r + 1, {-1, -1});
			}
			else
			{
				cin >> l >> r;
				pll val = get(1, 1, n + 1, l, r + 1);
				// cout<<val.first<<"  "<<val.second<<endl;
				ans += min(val.first, val.second);
			}
		}
		cout << ans << endl;
	}
}
