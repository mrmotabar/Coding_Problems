#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000 + 10];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int s = 1, e = 1;
	int i;
	for (i = 1; i < n; i++)
	{
		if (a[i] > a[i + 1])
		{
			s = i;
			break;
		}
	}
	for (i = s; i < n; i++)
	{
		if (a[i] < a[i + 1])
		{
			e = i;
			break;
		}
	}
	if (i == n)
	{
		e = n;
	}
	reverse(a + s, a + e + 1);
	for (int j = 1; j < n; j++)
	{
		if (a[j] > a[j + 1])
		{
			cout << "no";
			return 0;
		}
	}
	cout << "yes" << endl;
	cout << s << " " << e;
}
