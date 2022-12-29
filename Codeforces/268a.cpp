#include <iostream>
#include <cstdio>
using namespace std;
int a[40], b[40], t;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				t++;
			}
		}
	}
	cout << t;
}
