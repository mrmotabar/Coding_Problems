#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n, i = 1;
	cin >> n;
	int sum = 0;
	while (sum < n)
	{
		sum += (5 * i);
		i *= 2;
	}
	i /= 2;
	sum -= (5 * i);
	n -= sum;
	int t = n / i;
	if (n % i != 0)
	{
		t++;
	}
	if (t == 1)
	{
		cout << "Sheldon";
	}
	if (t == 2)
	{
		cout << "Leonard";
	}
	if (t == 3)
	{
		cout << "Penny";
	}
	if (t == 4)
	{
		cout << "Rajesh";
	}
	if (t == 5)
	{
		cout << "Howard";
	}
}
