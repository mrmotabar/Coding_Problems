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
int n;
bool caps;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (s == "CAPS")
		{
			caps = 1 - caps;
		}
		else
		{
			char c = s[0];
			if (caps == 1)
			{
				cout << char(int(c) - int('a') + int('A'));
			}
			else
			{
				cout << c;
			}
		}
	}
}
