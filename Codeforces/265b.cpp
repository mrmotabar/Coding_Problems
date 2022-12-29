#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int main()
{
	int n;
	cin >> n;
	int ans = 0;
	ans += n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ans += a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1])
		{
			ans += a[i] - a[i - 1] + 1;
		}
		if (a[i] < a[i - 1])
		{
			ans += a[i - 1] - a[i] + 1;
		}
		if (a[i] == a[i - 1])
		{
			ans++;
		}
	}
	cout << ans;
}
