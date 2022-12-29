#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		a[i] = n / m;
	}
	int x = n % m;
	for (x; x > 0; x--)
	{
		a[x]++;
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i++)
	{
		cout << a[i] << "  ";
	}
}
