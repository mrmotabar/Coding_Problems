#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int main()
{
	int n;
	cin >> n;
	int miin = 99999, mini = 0;
	int maax = 0, maxi = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > maax)
		{
			maax = a[i];
			maxi = i;
		}
		if (a[i] <= miin)
		{
			miin = a[i];
			mini = i;
		}
	}
	if (mini < maxi)
	{
		cout << n - mini + maxi - 2;
		return 0;
	}
	else
	{
		cout << n - mini + maxi - 1;
	}
}
