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
int n, a[MAX_N], hast[MAX_N], ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		hast[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		while (hast[i] > 1)
		{
			hast[i]--;
			int j = i + 1;
			while (hast[j] > 0)
			{
				j++;
			}
			hast[j]++;
			ans += j - i;
		}
	}
	cout << ans << endl;
}
