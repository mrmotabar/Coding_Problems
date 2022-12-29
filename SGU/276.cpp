#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int s, p;
	cin >> s >> p;
	int t = (p - s);
	if (t == 0)
	{
		cout << 0;
	}
	else if ((t >= 1) && (t < 300))
	{
		cout << 1;
	}
	else if ((t >= 300) && (t < 900))
	{
		cout << 2;
	}
	else if ((t >= 900) && (t < 1800))
	{
		cout << 3;
	}
	else if (t >= 1800)
	{
		cout << 4;
	}
}
