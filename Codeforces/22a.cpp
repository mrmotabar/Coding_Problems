#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int i = 0;
	while (a[i] == a[i + 1] && i < n)
	{
		i++;
	}
	if (i == n - 1)
	{
		cout << "NO";
	}
	else
	{
		cout << a[i + 1];
	}
}
