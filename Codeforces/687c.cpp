#include <iostream>
#include <cstdio>#
using namespace std;
int d[600][600];
int coin = 0;
int ans = 0;
int main()
{
	int n, k;
	cin >> n >> k;
	d[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> coin;
		for (int j = k - coin; j >= 0; j--)
		{
			for (int t = 0; t <= j; t++)
			{
				if (d[j][t] == 1)
				{
					d[j + coin][t] = 1;
					d[j + coin][t + coin] = 1;
				}
			}
		}
	}
	for (int i = 0; i <= k; i++)
	{
		if (d[k][i] > 0)
		{
			ans++;
		}
	}
	cout << ans << endl;
	for (int i = 0; i <= k; i++)
	{
		if (d[k][i] > 0)
		{
			cout << i << " ";
		}
	}
}
