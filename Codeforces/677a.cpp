#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, h, a, b = 0;
	cin >> n >> h;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a > h)
		{
			b++;
		}
	}
	cout << b + n;
}
