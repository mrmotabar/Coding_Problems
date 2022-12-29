#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000 + 10];
int main()
{
	int n, k, size = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			a[size++] = i + 1;
		}
	}
	int m, t;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		cout << a[t] << endl;
	}
}
