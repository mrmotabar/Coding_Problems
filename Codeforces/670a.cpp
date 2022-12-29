#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int max = 0, min = 0;
	min = (n / 7) * 2;
	max = min;
	if (n % 7 == 6)
	{
		min++;
	}
	if (n % 7 == 1)
	{
		max++;
	}
	if (n % 7 > 1)
	{
		max += 2;
	}
	cout << min << "   " << max;
}
