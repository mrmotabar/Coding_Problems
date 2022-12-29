/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k, ans = 0;
	cin >> n >> k;
	k = 240 - k;
	for (int i = 1; i <= n; i++)
	{
		if (k >= i * 5)
		{
			k -= i * 5;
			ans++;
		}
	}
	cout << ans;
}
