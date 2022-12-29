#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] * n == sum)
		{
			b[t++] = i + 1;
		}
	}
	cout << t << endl;
	for (int i = 0; i < t; i++)
	{
		cout << b[i] << " ";
	}
}
