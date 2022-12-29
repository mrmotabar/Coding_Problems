/*mohammadreza motabar*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define F first
#define S second
int n, l, r, x, ans;
int a[1000], c[10000];
bool check()
{
	int sum = 0;
	int min = 9999999, max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 2)
		{
			sum += c[i];
			if (c[i] < min)
			{
				min = c[i];
			}
			if (c[i] > max)
			{
				max = c[i];
			}
		}
	}
	if (sum <= r && sum >= l && max - min >= x)
	{
		return 1;
	}
	return 0;
}
inline void bt(int x)
{
	for (int i = 1; i <= 2; i++)
	{
		a[x] = i;
		if (x == n + 1)
		{
			// for(int j=1;j<=n;j++){
			//	cout<<a[j]<<" ";
			// }
			// cout<<endl;
			if (check())
			{
				ans++;
			}
			a[x] = 0;
			return;
		}
		bt(x + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	// sort(c+1,c+n+1);
	bt(1);
	cout << ans;
}
