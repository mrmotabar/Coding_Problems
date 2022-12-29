#include <iostream>
#include <cstdio>
#include <algorithm>
const int max_n = 100 * 1000 + 10;
long long int a[max_n];
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	a[0] = 999999999999;
	a[n + 1] = 9999999999999;
	for (int i = 1; i <= n; i++)
	{
		cout << min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1])) << " " << max(abs(a[i] - a[n]), abs(a[i] - a[1])) << endl;
	}
}
