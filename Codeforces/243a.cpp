/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
ll n, a[100000 + 100];
set<ll> ans, gh1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ans.insert(a[0]);
	gh1.insert(a[0]);
	for (int i = 1; i < n; i++)
	{
		set<ll> gh2;
		ans.insert(a[i]);
		gh2.clear();
		gh2.insert(a[i]);
		for (ll u : gh1)
		{
			gh2.insert(u | a[i]);
			ans.insert(u | a[i]);
		}
		gh1 = gh2;
	}
	cout << ans.size();
}
