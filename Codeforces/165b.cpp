#include <iostream>
#include <cstdio>
using namespace std;
int n, k;
int f(int mid)
{
	long long int sum = 0;
	while (mid > 0)
	{
		sum += mid;
		mid /= k;
	}
	if (sum >= n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	cin >> n >> k;
	bool c = false;
	int s = 0;
	int e = n;
	int jav = n;
	while (e - s > 1)
	{
		int mid = (s + e) / 2;
		if (f(mid) == 1)
		{
			e = mid;
		}
		else if (f(mid) == 0)
		{
			s = mid;
		}
		// cout<<s<<"  "<<e<<endl;
	}
	if (f(s) == 1)
	{
		cout << s;
	}
	else
	{
		cout << e;
	}
}
