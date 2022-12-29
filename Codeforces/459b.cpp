/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
ll n, a[2 * 100000 + 100], bmin = 0, bmax = 0, mina = 9999999999, maxa = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < mina)
		{
			mina = a[i];
			bmin = 0;
		}
		if (a[i] == mina)
		{
			bmin++;
		}
		if (a[i] > maxa)
		{
			maxa = a[i];
			bmax = 0;
		}
		if (a[i] == maxa)
		{
			bmax++;
		}
	}
	if (mina != maxa)
		cout << maxa - mina << " " << bmax * bmin;
	else
		cout << 0 << " " << bmax * (bmax - 1) / 2;
}
