#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, maax = 0;
pair<int, int> a[100000 + 10];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		if (a[i].second > maax)
		{
			maax = a[i].second;
		}
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i].second > a[i + 1].second)
		{
			cout << "Happy Alex";
			return 0;
		}
	}
	cout << "Poor Alex";
}
