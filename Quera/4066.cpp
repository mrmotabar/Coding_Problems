/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
string a, b;
int n, m;
map<string, string> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		mp[a] = b;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		if (!mp.count(a))
		{
			cout << "kachal! ";
		}
		else
		{
			cout << mp[a] << " kachal! ";
		}
	}
}
