/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int p, d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> p >> d;
	for (int i = 1; i <= 100; i++)
	{
		if ((d * i) % p <= p / 2)
		{
			cout << d * i;
			return 0;
		}
	}
}
