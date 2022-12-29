#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int main()
{
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sum = 0;
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++)
	{
		sum += a[i];
	}
	if (sum > s)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
}
