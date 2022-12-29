#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
void sort(int a[])
{
	for (int i = 0; i < m; i++)
	{
		int x = a[i];
		int j = i - 1;
		while ((a[j] > x) && (j >= 0))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
int main()
{
	cin >> n >> m;
	int a[m];
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	sort(a);
	int min = a[n - 1] - a[0];
	for (int i = 1; i < m - (n - 1); i++)
	{
		if ((a[i + (n - 1)] - a[i]) < min)
		{
			min = a[i + (n - 1)] - a[i];
		}
	}
	cout << min;
}
