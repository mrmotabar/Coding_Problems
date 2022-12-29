#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int x[100000];
int y[100000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i] != x[j] && y[i] != y[j])
			{
				cout << (abs(x[i] - x[j])) * (abs(y[i] - y[j]));
				return 0;
			}
		}
	}
	cout << -1;
}
