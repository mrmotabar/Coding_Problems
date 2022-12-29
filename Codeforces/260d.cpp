/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 100, INF = 1e9;
ll n, c[MAX_N], s[MAX_N], tsih, tsef;
vector<pair<ll, ll>> siah, sefid;
vector<pair<pair<ll, ll>, ll>> jav;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> s[i];
		if (c[i] == 1)
		{
			siah.pb({s[i], i});
			tsih++;
		}
		else
		{
			sefid.pb({s[i], i});
			tsef++;
		}
	}
	sort(siah.begin(), siah.end());
	sort(sefid.begin(), sefid.end());
	ll sef = 0, sih = 0;
	while (sef < tsef && sih < tsih)
	{
		if (siah[sih].first < sefid[sef].first)
		{
			sefid[sef].first -= siah[sih].first;
			jav.pb({{siah[sih].second, sefid[sef].second}, siah[sih].first});
			sih++;
		}
		else if (sefid[sef].first < siah[sih].first)
		{
			siah[sih].first -= sefid[sef].first;
			jav.pb({{sefid[sef].second, siah[sih].second}, sefid[sef].first});
			sef++;
		}
		else if (sefid[sef].first == siah[sih].first)
		{
			jav.pb({{sefid[sef].second, siah[sih].second}, siah[sih].first});
			siah[sih].first = 0;
			sefid[sef].first = 0;
			if (sef > sih)
			{
				sef++;
			}
			else
			{
				sih++;
			}
		}
	}
	if (sih < tsih - 1)
	{
		for (int i = sih; i < tsih; i++)
		{
			jav.pb({{siah[i].second, sefid[0].second}, 0});
		}
	}
	if (sef < tsef - 1)
	{
		for (int i = sef + 1; i < tsef; i++)
		{
			jav.pb({{sefid[i].second, siah[0].second}, 0});
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		cout << jav[i].first.first << " " << jav[i].first.second << " " << jav[i].second << endl;
	}
}
