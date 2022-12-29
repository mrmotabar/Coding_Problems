#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long m, n, sum = 0;
	cin >> n >> m;
	int min = n;
	if (m < min)
	{
		min = m;
	}
	int max = n;
	if (m > max)
	{
		max = m;
	}
	for (int i = 1; i <= min; i++)
	{
		sum += ((i + max) / 5) - (i / 5);
	}
	cout << sum;
}
