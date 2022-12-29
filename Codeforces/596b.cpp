#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long int a[1000000];
int main()
{
	long long int n;
	cin >> n;
	for (long long int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	long long int ans = 0, tem = 0;
	for (long long int i = 0; i < n; i++)
	{
		ans += abs(a[i] - tem);
		tem = a[i];
	}
	cout << ans;
}
