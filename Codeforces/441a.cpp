#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long int a[10000];
int main()
{
	long long int n, v, j = 0, m, p;
	bool les;
	cin >> n >> v;
	for (long long int k = 1; k <= n; k++)
	{
		cin >> m;
		les = false;
		for (long long int i = 0; i < m; i++)
		{
			cin >> p;
			if (p < v)
			{
				les = true;
			}
		}
		if (les)
		{
			a[j] = k;
			j++;
		}
	}
	sort(a, a + j);
	cout << j << endl;
	for (long long int i = 0; i < j; i++)
	{
		cout << a[i] << " ";
	}
}
