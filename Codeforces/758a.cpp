/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
ll a[100 + 100], n, maxa = 0, ans = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > maxa)
		{
			maxa = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		ans += maxa - a[i];
	}
	cout << ans;
}
