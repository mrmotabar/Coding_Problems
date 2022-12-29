#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int x[100000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	sort(x, x + n);
	int m, d;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> d;
		cout << upper_bound(x, x + n, d) - x << endl;
	}
}
