#include <iostream>
#include <cstdio>
using namespace std;
bool a[1000001];
int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= (n / i); j++)
		{
			a[j * i] = 1;
		}
	}
	int t = 0;
	for (int i = 2; i < n - 1; i++)
	{
		if (a[i] == 0 && a[i + 2] == 0 && i + 2 <= n)
		{
			t++;
		}
	}
	cout << t << endl;
	for (int i = 2; i < n - 1; i++)
	{
		if (a[i] == 0 && a[i + 2] == 0 && i + 2 <= n)
		{
			cout << 2 << " " << i << endl;
		}
	}
}
