#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, sum = 0, b = 0;
	cin >> n;
	int a[7];
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
	while (sum < n)
	{
		for (int i = 0; i < 7; i++)
		{
			sum += a[i];
			b = i;
			if (sum >= n)
			{
				break;
			}
		}
	}
	cout << b + 1;
}
