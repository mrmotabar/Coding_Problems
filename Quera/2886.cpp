/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int a, b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	a = 12 - a;
	if (a == 12)
	{
		a = 0;
	}
	b = 60 - b;
	if (b == 60)
	{
		b = 0;
	}
	if (a < 10)
	{
		cout << 0 << a;
	}
	else
	{
		cout << a;
	}
	cout << ":";
	if (b < 10)
	{
		cout << 0 << b;
	}
	else
	{
		cout << b;
	}
}
