#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			t++;
		}
	}
	if (t > 2)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
}
