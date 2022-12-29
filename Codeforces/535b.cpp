#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100000];
int luk(int x)
{
	if (x == 7)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int n;
	cin >> n;
	int i = 0;
	while (n > 0)
	{
		a[i] = n % 10;
		n /= 10;
		i++;
	}
	int sum = 0;
	for (int j = i - 1; j > 0; j--)
	{
		sum += luk(a[j]) * pow(2, j);
	}
	sum += luk(a[0]);
	cout << sum;
}
