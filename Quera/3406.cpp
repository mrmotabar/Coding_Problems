/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int a, b, c, d, x, y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> c;
	x = a;
	y = c;
	b = (a % 10) * 100;
	a /= 10;
	b += (a % 10) * 10;
	a /= 10;
	b += a;
	d = (c % 10) * 100;
	c /= 10;
	d += (c % 10) * 10;
	c /= 10;
	d += c;
	if (b > d)
	{
		cout << y << " < " << x;
	}
	else if (b == d)
	{
		cout << x << " = " << y;
	}
	else
	{
		cout << x << " < " << y;
	}
}
