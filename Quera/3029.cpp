/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
int x, y, z, w;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> x >> y >> z >> w;
	z -= x;
	w -= y;
	if (z >= 0)
	{
		cout << "Right";
	}
	if (z < 0)
	{
		cout << "Left";
	}
}
