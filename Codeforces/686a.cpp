#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long n, a, t = 0;
	char c;
	cin >> n >> a;
	long long b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> c >> b[i];
		if (c == '+')
			a += b[i];
		else if (c == '-' & a - b[i] >= 0)
		{
			a -= b[i];
		}
		else
			t++;
	}
	cout << a << " " << t;
}
