/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int a, b, c, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c;
	while (a >= 1 && b >= 2 && c >= 4)
	{
		a--;
		b -= 2;
		c -= 4;
		ans += 7;
	}
	cout << ans << endl;
}
