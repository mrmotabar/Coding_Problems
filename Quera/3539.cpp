/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n > 9)
	{
		ll s = 0, e = n;
		while (e > 0)
		{
			s += e % 10;
			e /= 10;
		}
		n = s;
	}
	cout << n;
}
