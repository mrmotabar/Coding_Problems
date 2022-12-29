#include <iostream>
#include <cstdio>
using namespace std;
void insertion(int a[])
{
	for (int i = 1; i <= 2; i++)
	{
		int x = a[i];
		int j = i - 1;
		while ((a[j] > x) && (j >= 0))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
int main()
{
	int a[3], b[3], c[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> c[i];
	}
	insertion(a);
	insertion(b);
	insertion(c);
	int d[3];
	d[0] = a[1];
	d[1] = b[1];
	d[2] = c[1];
	insertion(d);
	cout << d[1];
}
