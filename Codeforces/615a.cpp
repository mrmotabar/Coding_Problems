#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int main()
{
	string s[1000];
	int n, m;
	cin >> n >> m;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		int c;
		for (int j = 0; j < x; j++)
		{
			cin >> c;
			a[c]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (a[i] == 0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
