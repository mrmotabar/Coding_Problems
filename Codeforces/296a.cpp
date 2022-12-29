#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];
int main()
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[x]++;
		if (a[x] > (n + 1) / 2)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
