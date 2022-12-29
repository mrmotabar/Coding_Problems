/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int x, y, dx, dy, r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> x >> y >> r >> dx >> dy;
	if (x <= dx && dx <= x + r && dy <= y && dy >= y - r)
	{
		cout << "Mahdi";
	}
	else
	{
		cout << "Parsa";
	}
}
