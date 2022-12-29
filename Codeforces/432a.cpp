#include <iostream>
#include <cstdio>
using namespace std;
int n, k, ans, t;
int main()
{
	cin >> n >> k;
	int a[n + 10];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] <= 5 - k)
			ans++;
	}
	cout << ans / 3;
}
