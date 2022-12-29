/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_K = 2e6 + 10, INF = 1e9;
ll n, k, a[MAX_K];
int h[MAX_K];
set<ll> st;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	n -= k;
	n %= (k + 1);
	if (n == 0)
	{
		n = k + 1;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> a[i];
		if (a[i] <= k + 1)
		{
			h[a[i]]++;
		}
	}
	for (int i = 1; i <= k + 1; i++)
	{
		if (!h[i])
		{
			st.insert(i);
		}
	}
	for (int i = k + 1; i <= k + k + 1; i++)
	{
		ll ans = k + 1;
		ans = min(ans, *st.begin());
		if (ans == *st.begin())
		{
			st.erase(st.begin());
		}
		a[i] = ans;
		// cout<<a[i]<<" ";
		h[a[i]]++;
		if (i >= k + 1)
		{
			if (a[i - k] <= k + 1)
			{
				h[a[i - k]]--;
				if (h[a[i - k]] == 0)
				{
					st.insert(a[i - k]);
				}
			}
		}
	}
	cout << a[n + k];
}
