#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000 * 100 + 10];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = 0, t = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum > a[i])
		{
		}
		else
		{
			sum += a[i];
			t++;
		}
	}
	cout << t;
}
