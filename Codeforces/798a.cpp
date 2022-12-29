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
string s;
int far;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			far++;
		}
	}
	if (far > 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (far == 1)
	{
		cout << "YES" << endl;
		return 0;
	}
	if (far == 0 && s.size() % 2 == 1)
	{
		cout << "YES" << endl;
		return 0;
	}
	else
	{
		cout << "NO" << endl;
		return 0;
	}
}
