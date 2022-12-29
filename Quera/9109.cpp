/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int n, a[100 + 10], x, mine = 101;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a[101] = INF;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[x]++;
	}
	for (int i = 0; i <= 100; i++)
	{
		if (a[i] < a[mine] && a[i] != 0)
		{
			mine = i;
		}
	}
	cout << mine;
}
