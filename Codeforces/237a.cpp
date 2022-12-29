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
int n, a[MAX_N], maxx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int h, m;
	for (int i = 0; i < n; i++)
	{
		cin >> h >> m;
		a[h * 60 + m]++;
		if (a[h * 60 + m] > maxx)
		{
			maxx = a[h * 60 + m];
		}
	}
	cout << maxx;
}
