#include <iostream>
#include <cstdio>
using namespace std;
pair<int, int> dp[1000000];
int a[1000000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	dp[0] = {1, a[0]};
	int max = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > dp[i - 1].second)
		{
			dp[i] = {dp[i - 1].first + 1, a[i]};
		}
		else
		{
			dp[i] = {1, a[i]};
		}
		if (dp[i].first > max)
		{
			max = dp[i].first;
		}
	}
	cout << max;
}
