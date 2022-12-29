#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
pair<int, int> a[100000 + 10];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	cout << a[n - 1].second << " " << a[n - 2].first;
}
