#include <iostream>
#include <cstdio>
using namespace std;
int a[200000];
int main()
{
	int n, k;
	cin >> n >> k;
	int min2 = 0;
	int min = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i < k - 1)
		{
			min += a[i];
			min2 = min;
		}
		if (i == k - 1)
		{
			min2 += a[i];
		}
		if (i > k - 2)
		{
			if (min + a[i] - a[i - k] < min2)
			{
				min2 = min + a[i] - a[i - k];
				index = i - k + 1;
			}
			min += a[i] - a[i - k];
		}
		// cout<<min<<"  ";
	}
	cout << index + 1;
	// cout<<min;
}
