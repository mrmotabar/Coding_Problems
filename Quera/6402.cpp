/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 100 + 10, INF = 1e9;
int n;
string s[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for (int i = 1; i < n; i++)
	{
		cout << s[i] << " to " << s[i + 1] << ": ke ba in dar agar dar bande dar manand, dar manand.\n";
		for (int j = i + 1; j > 1; j--)
		{
			cout << s[j] << " to " << s[j - 1] << ": dar manand?\n";
		}
		for (int j = 1; j <= i; j++)
		{
			cout << s[j] << " to " << s[j + 1] << ": dar manand.\n";
		}
	}
}
