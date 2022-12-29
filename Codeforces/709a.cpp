#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000 + 10];
int main()
{
	int n, b, d;
	cin >> n >> b >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sum = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= b)
		{
			sum += a[i];
		}
		if (sum > d)
		{
			sum = 0;
			ans++;
		}
	}
	cout << ans;
}
