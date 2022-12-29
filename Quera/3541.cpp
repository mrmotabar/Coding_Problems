/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ll ans = 0;
	for (ll i = 0; i < (n / 2) + (n % 2); i++)
	{
		if (n - i > i && (n - i) / 2 + (n - i) % 2 <= i)
		{
			// cout<<i<<"  "<<i-(n-i)/2-(n-i)%2+1<<endl;
			ans += i - (n - i) / 2 - (n - i) % 2 + 1;
		}
	}
	cout << ans;
}
