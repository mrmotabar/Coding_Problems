/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
string s, z;
int l, r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	s = "1";
	while (s.size() <= 100000)
	{
		z = s;
		for (int i = 0; i < z.size(); i++)
		{
			if (z[i] == '0')
			{
				z[i] = '1';
			}
			else
			{
				z[i] = '0';
			}
		}
		s += z;
	}
	cin >> l >> r;
	for (int i = l - 1; i <= r - 1; i++)
	{
		cout << s[i];
	}
}
