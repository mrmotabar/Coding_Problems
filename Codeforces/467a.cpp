#include <iostream>
#include <cstdio>
using namespace std;
int b;
int main()
{
	int n, a[200];
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 2 * n; i = i + 2)
	{
		if (a[i] < a[i + 1] - 1)
		{
			b++;
		}
	}
	cout << b;
}
