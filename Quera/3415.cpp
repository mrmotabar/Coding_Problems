/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int n, ans;
vector<int> a[1000 + 10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
	}
	int maxe = 0;
	for (int i = 0; i <= 1000; i++)
	{
		sort(a[i].begin(), a[i].end());
		if (a[i].size() == 0)
		{
		}
		else if (a[i].size() == 1)
		{
			if (a[i][0] > maxe)
			{
				ans++;
				maxe = a[i][0];
			}
		}
		else if (a[i][a[i].size() - 1] > a[i][a[i].size() - 2])
		{
			if (a[i][a[i].size() - 1] > maxe)
			{
				ans++;
				maxe = a[i][a[i].size() - 1];
			}
		}
	}
	cout << ans;
}
