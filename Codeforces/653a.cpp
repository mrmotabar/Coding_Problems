#include <iostream>
#include <Cstdio>
int a[50000];
using namespace std;
int main()
{
	int n, max = 0;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[x]++;
		if (x > max)
		{
			max = x;
		}
	}
	for (int i = 1; i <= max - 2; i++)
	{
		if (a[i] > 0 && a[i + 1] > 0 && a[i + 2] > 0)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
