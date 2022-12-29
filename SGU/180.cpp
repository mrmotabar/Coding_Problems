#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long t;
void merge(int s, int m, int e, int a[], int n)
{
	int i = s, j = m + 1, b[n];
	for (int k = s; k <= e; k++)
	{
		if (i > m)
		{
			b[k] = a[j++];
		}
		else if (j > e)
		{
			b[k] = a[i++];
		}
		else if (a[i] < a[j])
		{
			b[k] = a[i++];
		}
		else
		{
			b[k] = a[j++];
		}
	}
	for (int k = s; k <= e; k++)
	{
		a[k] = b[k];
	}
}
void mergesort(int s, int e, int a[], int n)
{
	int mid = 0;
	if (s < e)
	{
		mid = (s + e) / 2;
		mergesort(mid + 1, e, a, n);
		mergesort(s, mid, a, n);
		for (int i = s; i <= mid; i++)
		{
			int w = (lower_bound(a + mid + 1, a + e + 1, a[i])) - a - mid - 1;
			t += w;
		}
		merge(s, mid, e, a, n);
	}
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	mergesort(0, n - 1, a, n);
	cout << t << endl;
}
