/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
ll a[3 + 2][2 + 2];
ll x, y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}
	if (a[0][0] == a[1][0])
	{
		x = a[2][0];
	}
	else if (a[1][0] == a[2][0])
	{
		x = a[0][0];
	}
	else
	{
		x = a[1][0];
	}
	if (a[0][1] == a[1][1])
	{
		y = a[2][1];
	}
	else if (a[1][1] == a[2][1])
	{
		y = a[0][1];
	}
	else
	{
		y = a[1][1];
	}
	cout << x << " " << y;
}
