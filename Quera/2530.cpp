/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
map<char, int> mp;
string s;
int ans = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	mp['A'] = 1;
	mp['B'] = 1;
	mp['C'] = 1;
	mp['D'] = 2;
	mp['E'] = 1;
	mp['F'] = 2;
	mp['G'] = 1;
	mp['H'] = 1;
	mp['I'] = 1;
	mp['J'] = 1;
	mp['K'] = 1;
	mp['L'] = 2;
	mp['M'] = 1;
	mp['N'] = 1;
	mp['O'] = 1;
	mp['P'] = 1;
	mp['Q'] = 1;
	mp['R'] = 1;
	mp['S'] = 1;
	mp['T'] = 2;
	mp['U'] = 1;
	mp['V'] = 1;
	mp['W'] = 1;
	mp['X'] = 1;
	mp['Y'] = 1;
	mp['Z'] = 1;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		ans *= mp[s[i]];
	}
	cout << ans;
}
