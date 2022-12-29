/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
vector<string> r, l;
string a, b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 4; i++)
	{
		cin >> a >> b;
		if (b == "R")
		{
			r.push_back(a);
		}
		else if (b == "L")
		{
			l.push_back(a);
		}
	}
	if (l.size() == 3)
	{
		cout << l[1];
		return 0;
	}
	if (r.size() == 3)
	{
		cout << r[1];
		return 0;
	}
	if (l.size() > 1)
	{
		cout << l[0];
	}
	else
	{
		cout << r[0];
	}
}
