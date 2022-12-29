/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k, r;
	cin >> k >> r;
	int ans = 999999;
	for (int i = 1; i <= 10; i++)
	{
		if ((k * i) % 10 == 0 || (k * i) % 10 == r)
		{
			ans = min(ans, i);
		}
	}
	cout << ans;
}
