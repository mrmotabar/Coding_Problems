#include <iostream>
#include <cstdio>
using namespace std;
int a[4];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[x]++;
	}
	cout << min((a[1] + a[2]), min((a[1] + a[3]), (a[3] + a[2])));
}
