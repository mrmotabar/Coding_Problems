#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int t = 1;
	int sum = 0;
	while (sum + t < k)
	{
		sum += t;
		t++;
	}
	// cout<<a[t-(sum-k+1)];
	cout << a[k - sum];
}
