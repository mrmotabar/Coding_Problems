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
int n, k;
string s;
map<char, int> cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		cnt[s[i]]++;
		if (cnt[s[i]] > k)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
