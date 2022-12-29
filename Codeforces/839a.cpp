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
int n, a[MAX_N], k, za, t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n && k > 0; i++)
	{
		cin >> a[i];
		za += a[i];
		int x = min(8, za);
		za -= x;
		k -= x;
		t++;
	}
	if (k > 0)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << t << endl;
}
