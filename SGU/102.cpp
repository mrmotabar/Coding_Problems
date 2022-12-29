#include <iostream>
#include <cstdio>
using namespace std;
int t;
int main()
{
	int n, u;
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		u = 0;
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0 && n % j == 0)
			{
				u++;
			}
		}
		if (u == 0)
		{
			t++;
		}
	}
	cout << t + 1;
}
