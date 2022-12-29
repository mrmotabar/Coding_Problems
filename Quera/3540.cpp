/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i <= (n / x); i++)
	{
		if ((n - (i * x)) % y == 0)
		{
			cout << i << "  " << (n - (i * x)) / y;
			return 0;
		}
	}
	cout << -1;
}
