#include <iostream>
#include <cstdio>
using namespace std;
int a[100000];
int main()
{
	int n, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		a[b]++;
	}
	int max = 0;
	for (int i = 0; i < 10000; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	cout << n - max;
}
