#include <iostream>
#include <cstdio>
using namespace std;
int a[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int b[100];
	cin >> n >> m;
	int index;
	int max;
	for (int j = 0; j < m; j++)
	{
		index = 0;
		max = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			if (b[i] > max)
			{
				max = b[i];
				index = i;
			}
		}
		a[index]++;
	}
	index = 0;
	max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			index = i;
		}
	}
	cout << index + 1;
}
