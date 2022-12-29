#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	int h = 0, l = 0, ama = 0;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i])
			{
				l++;
			}
			else if (a[j] > a[i])
			{
				h++;
			}
		}
		if (l == i - 1 || h == i - 1)
		{
			ama++;
		}
		l = 0;
		h = 0;
	}
	cout << ama;
}
