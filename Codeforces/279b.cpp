#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n, t;
	cin >> n >> t;
	int a[n], b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int time = 0;
	int ans = 0;
	int i = 0, j = 0, sum = 0;
	while (j < n)
	{
		sum += a[j];
		j++;
		while (sum > t)
		{
			sum -= a[i];
			i++;
		}
		if (ans < j - i)
		{
			ans = j - i;
		}
	}
	cout << ans;
}
