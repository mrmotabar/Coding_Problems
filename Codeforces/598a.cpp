#include <iostream>
#include <cstdio>
using namespace std;
long long int a[100000 + 10];
long long int two[100];
int main()
{
	two[0] = 1;
	for (int i = 1; i < 60; i++)
	{
		two[i] = 2 * two[i - 1];
	}
	long long int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a[i];
		long long int temp = 0;
		while (a[i] >= two[temp])
		{
			temp++;
		}
		cout << (a[i] * (a[i] + 1)) / 2 - 2 * (two[temp] - 1) << endl;
	}
}
