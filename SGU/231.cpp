#include <iostream>
#include <cstdio>
using namespace std;
long long t;
int aval(int a)
{
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	for (int i = 2; i * i <= (a + 2); i++)
	{
		if ((a + 2) % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	int a[100000];
	cin >> n;
	for (int i = 3; i < n - 1; i += 2)
	{
		if (aval(i) == 1)
		{
			a[t] = i;
			t++;
		}
	}
	cout << t << endl;
	for (int i = 0; i < t; i++)
	{
		cout << 2 << " " << a[i] << endl;
	}
}
